#include "vectorquantizer.h"
#include <cassert>

using namespace std;

VectorQuantizer::VectorQuantizer()
{}

VectorQuantizer::VectorQuantizer(string tamanho, int codeBookSize)
{
  m_vectorSize = tamanho;
  m_codeBookSize = codeBookSize;
}

vector<Mat> VectorQuantizer::Train(vector<string> imagesList, string dim, int codeBookSize = 256)
{  
  m_codeBookSize = codeBookSize;
  cout << "Abrindo imagens \n";
  // recebe: uma lista de imagens
  // retorna: um vetor de imagens
  vector<Mat> images = OpenImages (imagesList); 
  
  cout << "Imagem de referencia:\n" << images[0] << endl;
  if(false)
    { // testando imagens
      namedWindow("Display Image", WINDOW_AUTOSIZE);
      for(auto i : images)      
        {
          imshow("Display Image", i);
          waitKey();
        }
      exit(0);
    }
  
  cout << "vetorizando imagens \n";
  // Recebe: um vetor de imagens e as dimensões do vetor na forma de um ponto (x,y). 
  // Retorna: um vetor de vetoresDasImagems
  Point vectorSizes = Str2Dim(dim);
  if(false)
    { // testando pontos
      cout << "\nPoint.x = " << vectorSizes.x << ", Point.y = " << vectorSizes.y << endl;
    }
  vector<Mat> vectorBucket = Vectorize (images, vectorSizes);
  if(false)
    {
      for(uint i = 0; i < vectorBucket.size (); i++)
        cout << "Vetor " << i << " = " << vectorBucket[i] << endl;
      exit(0);
    }
  
  cout << "Criando Codebook \n";
  // Recebe: um vetor de vetoresDasImagems
  // Retorna: um codebook[m_codebookSize] a partir dos vetores aleatórios escolhidos da entrada
  vector<Mat> codebook = MakeCodebook(vectorBucket);
  if(true)
    {
      for(uint i = 0; i < codebook.size (); i++)
        cout << "codebook " << i << " = " << codebook[i] << endl;
      //      exit(0);
    }
  
  // Cria um balde para cada codigo do codebook
  vector<vector<Mat>> codebookBuckets(m_codeBookSize); 
  
  cout << "Iniciando calculos: \n";
  vector<Mat> newCodebook;
  bool changes;
  do
    {
      changes = false;
      cout << "Distribuindo vetores pelos baldes \n";
      // enche os bandes do codebook com os menores sda entre os (vetoresDasImagens,codigosDoCodebook)
      codebookBuckets = FillBuckets (vectorBucket, codebook);
      
      if(false)
        {
          for(uint i = 0; i < codebookBuckets.size (); i++)
            cout << "codebookBuckets " << i << " = " << (codebookBuckets[i]).size() << endl;
          exit(0);
        }
      
      cout << "Calculando a média de cada balde \n";
      // calcula o vetor médio de cada balde
      newCodebook = CalcAverageOfBucket (codebookBuckets);
      
      if(false)
        {
          cout << "Mostrando novo codebook" << endl;
          for (uint i = 0; i < newCodebook.size (); i++)
            cout << 
                    "New Codebook = " << newCodebook[i] <<
                    ", Codebook = " << codebook[i] <<
                    endl;
          //          exit(0);
        }
      
      cout << "Atualizando codebook" << endl;
      for (uint l = 0; l < codebook.size (); l++)
        {
          if (sum(codebook[l] != newCodebook[l]) != Scalar(0,0,0,0))
            {
              codebook = newCodebook;
              changes = true;
            }
        }
    }while (changes);
  
  cout << "CABÔÔÔÔÔÔ \n";
  return codebook;
}

vector<Mat> VectorQuantizer::OpenImages(vector<string> imagesList)
{
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
  
  
  // PARA cada imagem fornecida
  for (auto imagem : images)
    {
      vector<Mat> imageVectors;
      
      // Vetorize a imagem
      imageVectors = Vectorize(imagem, vectorSizes);
      
      // INSIRA a os vetores da imagem no balde
      vectorsBucket.insert (vectorsBucket.end (),
                            imageVectors.begin (),
                            imageVectors.end ());
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
        
        //        namedWindow("Display Image", WINDOW_AUTOSIZE);
        //        imshow("Display Image", vetor);
        //        waitKey();
      }
  
  assert((vectorsBucket.size () != 0));
  return vectorsBucket;
}

vector<vector<Mat>> VectorQuantizer::FillBuckets(vector<Mat> vectorBucket, vector<Mat> codebook)
{
  Mat matOfAbsoluteDifference;
  vector<vector<Mat>> codebookBuckets(m_codeBookSize);
  uint indexOfSmallerCode;
  
  // maior diferença possível matriz preta - matriz branca = |0-255|*totalPixel = vectorBucket[0].total ()*255
  Scalar menorDiff;
  
  // PARA cada vetor do balde
  //  for (auto vect : vectorBucket)
  for (uint j = 0; j < vectorBucket.size (); j++)
    {
      cout << "Procurando balde para o vetor " << j << "/" << vectorBucket.size () << endl;
      menorDiff = Scalar(vectorBucket[0].total ()*255);
      // PARA cada codigo do codebook
      for (uint i = 0; i < codebook.size (); i++)
        {
          // calcula a matriz de diferenças absolutas entre vect e um codigo do codebook
          absdiff (vectorBucket[j],codebook[i], matOfAbsoluteDifference);
          
          // Soma todos as diferenças
          Scalar totalDiff = sum (matOfAbsoluteDifference);
          
          // Se essa é a manor diferença até agora
          if (totalDiff[0] < menorDiff[0])
            {               
              // Atualize o menor SDA
              menorDiff[0] = totalDiff[0];
              
              // Salve o indice do codebook que tem esse menor SDA
              indexOfSmallerCode = i;
            }
        }
      
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
  
  // Para cada balde calcule o vetor médio
  for (auto bucket : codebookBuckets)//  for (uint i = 0; i < codebookBuckets.size (); i++)
    {
      // auto bucket = codebookBuckets[i];
      averageVector = Mat(m_vectorSizes.y, m_vectorSizes.x, CV_32S, Scalar(0));
      
      cout << "pegou balde " << i++ << endl;
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
  
  return newCodebook;
}

void VectorQuantizer::Quantize(vector<Mat> codebook, string imageFile, string dim, int codeBookSize = 256)
{
  m_codeBookSize = codeBookSize;
  Mat imgInput = imread (imageFile,IMREAD_GRAYSCALE);
  vector<Mat> vectorBucket = Vectorize (imgInput, Point(Str2Dim (dim)));
  uint minSad;
  int codeIndex;
  fstream output;
  uint indexSize = 2;
  output.open (imageFile, ios::out| ios::binary);
  
  for (uint j = 0; j < vectorBucket.size (); j++)
    {
      for(uint i = 0; i < codebook.size (); i++)
        {
          Mat matDiff;
          absdiff (vectorBucket[j],codebook[i], matDiff);
          Scalar sumAbsDiff = sum (matDiff);
          if (sumAbsDiff[0] < minSad)
            {
              minSad = sumAbsDiff[0];
              codeIndex = i;
            }
        }
      output.write ((char *) &codeIndex, indexSize);
      
      vectorBucket[j] = codebook[codeIndex];
    }
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
  m_vectorSizes = vectorSize;
  return vectorSize;
}

vector<Mat> VectorQuantizer::MakeCodebook(vector<Mat> vectorBucket)
{
  vector<Mat> codebook(m_codeBookSize);
  RNG RandonGenerator;
  int theChosenVector;
  
  for(uint i = 0; i < codebook.size (); i++)
    {
      // FAZ um sorteio para escolher um vetor para o codebook
      // ENQUANTO o vetor sorteado é igual a algum que já está no codebook.
      
      bool flag;
      do
        {
          flag = false;
          theChosenVector = RandonGenerator.uniform(0, vectorBucket.size ()); 
          for (auto k : codebook)
            if (sum (vectorBucket[theChosenVector] != k ) == Scalar(0,0,0,0)) flag = true;
        } while (flag);
      
      // apagar
      //      do
      //        {
      //          theChosenVector = RandonGenerator.uniform(0,vectorBucket.size ());          
      //        } while (sum (vectorBucket[theChosenVector] != codebook[i]) != 0);
      
      // ATRIBUI elemento sorteado ao codebook
      codebook[i] = vectorBucket[theChosenVector];
    }
  
  return codebook;
}
