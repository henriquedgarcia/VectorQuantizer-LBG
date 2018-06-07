#include "vectorquantizer.h"
#include <cassert>

using namespace std;

VectorQuantizer::VectorQuantizer()
{}

vector<Mat> VectorQuantizer::Train(vector<string> imagesList, string dim, int codeBookSize = 256)
{
  m_vectorSizes = Str2Dim(dim);
  
  cout << "vetorizando imagens para treinamento\n";    
  vector<Mat> imagesVector = OpenImages (imagesList);
  if(false)// Mostrando imagens
    { 
      namedWindow("Display Image", WINDOW_AUTOSIZE);
      for(Mat i : imagesVector)      
        {
          imshow("Display Image", i);
          waitKey();
        }
      exit(0);
    }  
  
  // Vetorizando imagens
  vector<Mat> vectorBucket = Vectorize (imagesVector, m_vectorSizes);
  
  // mostra vetores
  if(false) for (auto vec : vectorBucket) ShowVectorOfMat(vec);
  
  // Criando codebooks
  cout << "Criando Codebook \n";
  vector<Mat> codebook = MakeCodebook(vectorBucket, codeBookSize);
  
  // Mostra o codebook
  if(false) ShowVectorOfMat(codebook);
  
  // Cria um balde para cada codigo do codebook
  vector<vector<Mat>> codebookBuckets(codebook.size ());
  
  // Loop de treinamento
  cout << "\n\nIniciando treinamento\n";
  vector<Mat> newCodebook;
  bool changes;
  
  do 
    {
      changes = false;
      cout << "\nDistribuindo vetores pelos baldes \n";
      
      // enche os bandes do codebook com os menores sda entre os (vetoresDasImagens,codigosDoCodebook)
      codebookBuckets = FillBuckets (vectorBucket, codebook);
      
      // mostra a quantidade de vetores em cada balde do codebook
      if(false) 
        {
          for(uint i = 0; i < codebookBuckets.size (); i++)
            cout << "Quantidade de vetores em codebookBuckets[" << i << "] = " << (codebookBuckets[i]).size() << endl;
          // exit(0);
        }
      
      cout << "Calculando a média de cada balde \n";
      newCodebook = CalcAverageOfBucket (codebookBuckets);
      
      // Comparando novo codebook
      if(false) 
        {
          cout << "Comparando codebook" << endl;
          CompareVectorOfMat(newCodebook, codebook);
        }
      
      cout << "\nAtualizando codebook" << endl;
//      for (uint l = 0; l < codebook.size (); l++)
//        {
//          if (sum(codebook[l] != newCodebook[l]) != Scalar(0,0,0,0))
//            {
//              if(true) cout << "New Codebook["<< l<<"] = " << newCodebook[l] << ", Codebook = " << codebook[l] << endl;
//              codebook = newCodebook;
//              changes = true;
//            }
//        }
      
      changes = CheckCodebookChanges(codebook, newCodebook);
      if (changes) codebook = newCodebook;
    } while (changes);
  
  cout << "CABÔÔÔÔÔÔ \n";
  return codebook;
}

vector<Mat> VectorQuantizer::OpenImages(vector<string> imagesList)
{
  // recebe: uma lista de imagens
  // retorna: um vetor de imagens
  
  vector<Mat> images;
  Mat img;
  
  // PARA cada nome na lista de arquivos
  for (auto filename : imagesList)
    {
      // ABRA a imagem
      img = imread(filename, IMREAD_GRAYSCALE);
      
      // COLOQUE a imagem no final da lista de imagens abertas
      images.push_back (img);
      
      // VERIFIQUE se a imagem aberta não está vazia
      assert (!(img.data == NULL));   
    }
  
  return images;
}

vector<Mat> VectorQuantizer::Vectorize(vector<Mat> images, Point vectorSizes)
{
  vector<Mat> vectorsBucket;  
  vector<Mat> imageVectors;
  
  // PARA cada imagem fornecida
  for (Mat imagem : images)
    {
      // Vetorize a imagem
      imageVectors = Vectorize(imagem, vectorSizes);
      
      // INSIRA a os vetores da imagem no balde
      vectorsBucket.insert (vectorsBucket.end (),
                            imageVectors.begin (), imageVectors.end ());
    }
  
  // Verifique se o balde não está vazio
  assert((vectorsBucket.size () != 0));
  
  return vectorsBucket;
}

vector<Mat> VectorQuantizer::Vectorize(Mat imagem, Point vectorSizes)
{
  Mat vetor;
  vector<Mat> vectorsBucket;
  
  for (int i = 0; i < imagem.rows; i += vectorSizes.y)
    for (int j = 0; j < imagem.cols; j += vectorSizes.x)
      {
        vetor = Mat(imagem, Rect(j, i, vectorSizes.x, vectorSizes.y));        
        vectorsBucket.push_back (vetor);
      }
  
  // Assegura que o balde não está vazio
  assert((vectorsBucket.size () != 0));
  return vectorsBucket;
}

vector<vector<Mat>> VectorQuantizer::FillBuckets(vector<Mat> vectorBucket, vector<Mat> codebook)
{
  Mat matOfAbsoluteDifference;
  vector<vector<Mat>> codebookBuckets(codebook.size ());
  uint indexOfSmallerCode;
  
  // 
  Scalar menorDiff;
  
  cout << "Procurando balde para o vetor tamanho "<< vectorBucket.size () << "\n";
  for (uint j = 0; j < vectorBucket.size (); j++)
    {
      // Mostre o progresso a cada 10 vetores
      // Reiniciando a menor diferença = maior diferença possível é matriz preta - matriz branca = |0-255|*totalPixel = vectorBucket[0].total ()*255
      
//      if(j%1000 ==0) cout << j << "/" << vectorBucket.size () << ", ";
      menorDiff = Scalar(vectorBucket[0].total ()*255);
      
      for (uint i = 0; i < codebook.size (); i++)
        {
          // PARA cada codigo do codebook
          // calcule a matriz de diferenças absolutas entre vect e um codigo do codebook
          // E então Soma todos as diferenças
          
          absdiff (vectorBucket[j],codebook[i], matOfAbsoluteDifference);
          Scalar totalDiff = sum (matOfAbsoluteDifference);
          
          if (totalDiff[0] < menorDiff[0])
            {     
              // Se essa é a menor diferença até agora
              // Atualize o menor SDA
              // Salve o indice do codebook que tem esse menor SDA
              
              menorDiff[0] = totalDiff[0];
              indexOfSmallerCode = i;
            }
        }      
      
      // Coloque o vetor no balde de menor diferença apontado pelo indice
      codebookBuckets.at (indexOfSmallerCode).push_back (vectorBucket[j]);      
    }
  
  // retorne o balde dos codebooks cheio
  return codebookBuckets;
}

vector<Mat> VectorQuantizer::CalcAverageOfBucket(vector<vector<Mat> > codebookBuckets)
{
  Mat uintVector;
  Mat averageVector;
  vector<Mat> newCodebook;
  int i = 0;
  //  int j = 0;
  
  cout << "Calculando balde ";
  // Para cada balde calcule o vetor médio
  for (auto bucket : codebookBuckets)//  for (uint i = 0; i < codebookBuckets.size (); i++)
    {
      // auto bucket = codebookBuckets[i];
      averageVector = Mat(m_vectorSizes.y, m_vectorSizes.x, CV_32S, Scalar(0));
      
      cout << i++ << ", ";
      
      //      j = 0;
      // PARA cada vetor do balde
      for (auto vect : bucket)
        {
          //          cout << "pegou vetor " << j++ << " = " << vect << endl;    
          vect.convertTo (uintVector, CV_32S);
          // Some todas os vetoresas matrizes
          averageVector += uintVector;
        }
      
      //      cout << "Vetor soma =  " << averageVector << endl;   
      
      averageVector = averageVector / ((int) bucket.size ());      
      averageVector.convertTo (averageVector,CV_8U);
      
      //      cout << "Vetor media =  " << averageVector << endl;   
      
      newCodebook.push_back (averageVector);
    }
  cout << endl;
  return newCodebook;
}

bool VectorQuantizer::CheckCodebookChanges(vector<Mat> codebook, vector<Mat> newCodebook)
{
  // Para código do codebook
  // Se a diferença entre os códigos forem diferente de zero
  
  for (uint i = 0; i < codebook.size (); i++)
    if (sum(codebook[i] != newCodebook[i]) != Scalar(0,0,0,0))
      {
        // Se algum código do novo codebook for diferente, mostre ele
        if(false) cout << "New Codebook[" << i << "] = " << newCodebook[i] << ", Codebook = " << codebook[i] << endl;
        cout << "Encontrada diferença. Atualizando. \n";
        return true;
      }
  
  // se não detectar nenhuma mudança, retorne false.
  return false;
}

void VectorQuantizer::Quantize(vector<Mat> codebook, string imageFile, string dim, int codeBookSize)
{
  m_vectorSizes = Point(Str2Dim (dim));
  
  Mat imgInput = imread (imageFile,IMREAD_GRAYSCALE);
  assert(imgInput.data != 0);
  vector<Mat> vectorBucket = Vectorize (imgInput, m_vectorSizes);
  Scalar minSad;
  int codeIndex;
  fstream output;
  uint indexSize;
  if (codeBookSize <= 256) indexSize = 1;
  else indexSize = 2;
  output.open (string("0-Saida-")+dim+string("-")+to_string(codeBookSize)+string("-")+imageFile+string(".LBG"), ios::out| ios::binary);
  
  cout << "Quantizando " << imageFile << ", dim = " << dim << ", codeBookSize = " << codeBookSize << endl;
  for (uint j = 0; j < vectorBucket.size (); j++)
    {
      //      if(j%10 ==0)
      //        cout << dec << j << "/" << vectorBucket.size () << ", ";
      
      minSad = Scalar(vectorBucket[0].total ()*255);
      for(uint i = 0; i < codebook.size (); i++)
        {
          Mat matDiff;
          absdiff (vectorBucket[j],codebook[i], matDiff);
          Scalar sumAbsDiff = sum (matDiff);
          
          if (sumAbsDiff[0] < minSad[0])
            {
              minSad[0] = sumAbsDiff[0];
              codeIndex = i;
            }
        }
      if(false) {cout << "Encontrado! Trocando vectorBucket["<< j<<"] = \n" 
                      << vectorBucket[j] << 
                         "\nPor codebook["<< codeIndex<<"] = \n" << 
                         codebook[codeIndex] << 
                         endl;
          cout << "escreveu o caractere = " << hex << codeIndex << endl << endl;}      
      // retorna indice
      output.write ((char *) &codeIndex, indexSize);
      
      // Atualiza imagem com o novo codigo      
      for(MatIterator_<uchar> it1 = vectorBucket[j].begin<uchar>(), it2 = codebook[codeIndex].begin<uchar>(); 
          it1 != vectorBucket[j].end<uchar>(); 
          ++it1, ++it2)
        {          
          //          cout << dec << (int) *it1 << " e " << (int) *it2 << endl;     
          *it1 = *it2;    
          //          cin.get ();
          
        }
      //      vectorBucket[j] = codebook[codeIndex];      
    }
  
  imwrite (string("0-Saida-")+string(dim)+string("-")+to_string(codeBookSize)+string("-")+imageFile, imgInput);
  cout << "PSNR = " << PSNR (imgInput, imread (imageFile,IMREAD_GRAYSCALE)) << endl;  
  cout << "PSNR (ref.)= " << PSNR (imread (imageFile,IMREAD_GRAYSCALE),imread (imageFile,IMREAD_GRAYSCALE)) << endl;  
  
  
  ///////////////////////////////////////////////////////////
  //  Calculando métricas
}

//imwrite ("saida.tiff", imgInput, const std::vector<int> &params);
//vector<Mat> VectorQuantizer::UpdateCodebook(vector<Mat> codebook, vector<Mat> newCodebook)
//{
//  // se atualizar retorna true
//  bool saida = false;
//  Mat matDiff;

//  for(uint i = 0; i < codebook.size (); i++)
//    {
//      absdiff (codebook[i], newCodebook[i], matDiff);
//      cout << "\nCodebook["<< i << "] = " << codebook[i] << 
//              "newCodebook["<< i << "] = " << newCodebook[i] << 
//              "matDiff = " << matDiff << 
//              endl;

//      if (sum(matDiff) != Scalar(0,0,0,0))
//        {
//          cout << "MUDANÇA DETECTADA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//          codebook[i] = newCodebook[i];
//          if (saida == false)
//            saida = true;
//        }
//    }
//  cin.get();
//  return codebook;
//}

Point VectorQuantizer::Str2Dim(string dim)
{
  string s_linha;
  string s_coluna;
  bool flag = false;
  
  for (char c : dim)
    {
      if (c == 'x')
        {
          flag = true;
          continue;
        }
      
      if(flag == false)
        s_linha.insert(s_linha.end(), c);
      else
        s_coluna.insert(s_coluna.end(), c);
    }
  
  Point vectorSize;
  vectorSize.y = stoi(s_linha);
  vectorSize.x = stoi(s_coluna);
  return vectorSize;
}

void VectorQuantizer::ShowVectorOfMat(vector<Mat> codebook)
{
  cout << "Vector<Mat>" << endl;
  for(uint i = 0; i < codebook.size (); i++)
    {
      cout << "(" << i << ")" << codebook[i] << " = \n";
    }
}

void VectorQuantizer::SaveCodebook(vector<Mat> codebook, string dimensoes, int codebookSize)
{
  cout << "Gravando codebook" << endl;
  
  fstream codebookFstream;
  Point dimensao = VectorQuantizer::Str2Dim (dimensoes);
  string nome = "codebooks/codebook-" + dimensoes + "-" + to_string(codebookSize) + ".cdbk";
  codebookFstream.open (nome, ios::out|ios::binary);
  
  for(uint code = 0; code < codebook.size (); code++)
    for(int i = 0; i < dimensao.y; i++)
      for(int j = 0; j < dimensao.x; j++)
        codebookFstream.put (codebook[code].at<uchar>(i,j));
  
  codebookFstream.close ();
  cout << "Gravando codebook - OK!" << endl;
}

void VectorQuantizer::CompareVectorOfMat(vector<Mat> codebook1, vector<Mat> codebook2)
{
  for (uint i = 0; i < codebook1.size (); i++)
    cout << 
            "\n New Codebook[" << i << "] = " << codebook1[i] <<
            "\n, Codebook[" << i << "] = " << codebook2[i] <<
            endl;
}

vector<Mat> VectorQuantizer::MakeCodebook(vector<Mat> vectorBucket, int codeBookSize)
{
  // Recebe: um vetor de vetoresDasImagems
  // Retorna: um codebook[m_codebookSize] a partir dos vetores aleatórios escolhidos da entrada
  
  vector<Mat> codebook(codeBookSize);
  RNG RandonGenerator;
  int theChosenVector;
  
  
  for(uint i = 0; i < codebook.size (); i++)
    {
      // FAZER um sorteio para escolher um vetor para o codebook
      // ENQUANTO o vetor sorteado é igual a algum que já está no codebook.
      
      bool flag;
      do
        {
          flag = false;
          theChosenVector = RandonGenerator.uniform(0, vectorBucket.size ()); 
          for (auto k : codebook)
            if (sum (vectorBucket[theChosenVector] != k ) == Scalar(0,0,0,0)) flag = true;
        } while (flag);      
      
      codebook[i] = vectorBucket[theChosenVector];
    }
  
  return codebook;
}
