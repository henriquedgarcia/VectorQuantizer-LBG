#include "vectorquantizer.h"
#include <cassert>

using namespace std;

VectorQuantizer::VectorQuantizer()
{}

VectorQuantizer::VectorQuantizer(string tamanho, int codeBookSize)
{
  m_vectorSize = tamanho;
  m_codeBookSize = codeBookSize;
  m_codeBook = vector<vector*> (m_codeBookSize);
}

vector<vector<uchar> > VectorQuantizer::Train(vector<string> imagesList, string dim)
{
  //  1 chutar vetor dos codebooks
  
  //  2 Nquanto houver imagem
  //  3   Pegar uas imagens
  //  4   Segmentar essas imagens em vetores
  
  //  5 Calcular a soma das diferenças absolutas (SDA) entre vetores das imagens (x) e o do codebook (y) Sum(|xn-yn|), n=1:vetor.size()
  //  6 indexar vetores da imagem ao vetor do codebook de menor SDA.
  
  //  7 calcular vetor médio de todos os vetores da imagem indexados por cada elemento do codebook
  
  //  8 se vetor medio daquele vetor do codebook for diferente do vetor do codebook
  //  9   subtitua o vetor do codebook
  
  //  10 só parar quanto todos os vetores dos codebook não mudarem mais
  
  //  for (i = 0; i < imagens.size (); i++)
  
  vector<Mat> images = OpenImages (imagesList); 
  vector<Mat> vectorBucket = Vectorize (images, dim);
  vector<Mat> codebook = MakeCodebook(vectorBucket);
  vector<vector<Mat>> indice(codebooksize); // aqui armazenamos os vetores de menor SDA. ex. indice(4) será um vetor<mat> com todos os vetores que possuem menor SDA com o codebook[4]
  
  FindSmallerSAD()
//  while("centroids anterior != centroide atual");
  {
    for (auto vector : vectorBucket)
      {
        for (int i; i < codebook.size(); i++)
          {
            int erro = SDA (vector,codebook[i]);
            if (erro < menorErro) 
              {
                smallerError = erro;
                smallerCode = i;
              }
          }
        
        indice[smallerCode].pushback(vector);
      }
  }
  
  
  
  //  Sum of absolute differences (SAD)
}

vector<Mat> VectorQuantizer::OpenImages(vector<string> imagesList)
{
  vector<Mat> images;
  Mat img;
  
  for (auto filename : imagesList)
    {
      img = imread(filename, IMREAD_GRAYSCALE);
      images.push_back (img);
      assert (!(m_image.data == NULL));   
    }
  
  return images;
}

vector<Mat> VectorQuantizer::Vectorize(vector<Mat> images, string dim)
{
  vector<Mat> vectorsBucket;
  
  for (auto imagem : images)
    {
      vectorsBucket.push_back (Vectorize(imagem, dim));
    }
  
  assert((vectorsBucket.size () != 0));
  
  return vectorsBucket;
}

vector<Mat> VectorQuantizer::Vectorize(Mat imagem, string dim)
{
  point vectorSizes = Str2Dim(dim);
  Mat vetor;
  vector<Mat> vectorsBucket;
  for (int i = 0; i < imagem.rows; i += vectorSizes.y)
    for (int j = 0; j < imagem.cols ; j += vectorSizes.x)
      {
        vetor = Mat(imagem, Rect(i, j, linha, coluna));        
        vectorsBucket.push_back (vetor);
        
        //        namedWindow("Display Image", WINDOW_AUTOSIZE);
        //        imshow("Display Image", vetor);
        //        waitKey();
      }
  
  assert((vectorsBucket.size () != 0));
  return vectorsBucket;
}

void VectorQuantizer::Quantize(string nameInput)
{
  
}

Point VectorQuantizer::Str2Dim(string dim)
{
  string s_linha;
  string s_coluna;
  bool flag = false;
  
  for (char c : nome)
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
  
  Point dim;
  dim.y = stoi(s_linha);
  dim.x = stoi(s_coluna);
  
  return dim;
}

//vector<Mat *> VectorQuantizer::Vectorize(Mat imgInput)

vector<Mat> VectorQuantizer::Vectorize(string)
{
  
}

