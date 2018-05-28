#ifndef VECTORQUANTIZER_H
#define VECTORQUANTIZER_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <fstream>

using namespace std;
using namespace cv;

class VectorQuantizer
{
public:
  // Atributos
  int m_codeBookSize = 256;
  string m_vectorSize = "1x2";
  Point m_vectorSizes;
  
  // Variaveis de estado
  vector<Mat> m_images;
  vector<Mat *> m_imagesVectors;
  
  // construtores
  VectorQuantizer();
  VectorQuantizer(string tamanho, int codeBookSize);
  
  // Treinamento
  vector<Mat> Train(vector<string> imagens, string dim, int codeBookSize);
  vector<Mat> MakeCodebook(vector<Mat> vectorBucket); // OK !!!!!
  vector<Mat> Vectorize(vector<Mat> images, Point vectorSizes); // OK !!!!!
  vector<Mat> Vectorize(Mat imagem, Point vectorSizes); // OK !!!!!
  vector<vector<Mat>> FillBuckets(vector<Mat> vectorBucket, vector<Mat> codebook);
  vector<Mat> CalcAverageOfBucket(vector<vector<Mat>> codebookBuckets);
  vector<Mat> UpdateCodebook(vector<Mat> codebook, vector<Mat> newCodebook);
    
  // Depois que o codebook já foi feito, quantiza-se
   void Quantize(vector<Mat> codebook, string imageFile, string dim, int codeBookSize);
  
  // tools
  Point Str2Dim(string dim); // OK!!!!
  vector<Mat> OpenImages(vector<string> NameInput); // OK!!!!
};

#endif // VECTORQUANTIZER_H
