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
  string m_vectorSize;
  Point m_vectorSizes;
  
  // Variaveis de estado
  vector<Mat> m_images;
  vector<Mat *> m_imagesVectors;
  
  // construtores
  VectorQuantizer();
  VectorQuantizer(string tamanho, int codeBookSize);
  
  // Treinamento
  vector<Mat> Train(vector<string> imagens, string dim, int codeBookSize);
  vector<Mat> MakeCodebook(vector<Mat> vectorBucket, int codeBookSize); // OK !!!!!
  vector<Mat> Vectorize(vector<Mat> images, Point vectorSizes); // OK !!!!!
  vector<Mat> Vectorize(Mat imagem, Point vectorSizes); // OK !!!!!
  vector<vector<Mat>> FillBuckets(vector<Mat> vectorBucket, vector<Mat> codebook);
  vector<Mat> CalcAverageOfBucket(vector<vector<Mat>> codebookBuckets);
  bool CheckCodebookChanges(vector<Mat> codebook, vector<Mat> newCodebook);
    
  // Quantização
   void Quantize(vector<Mat> codebook, string imageFile, string dim, int codeBookSize);
  
  // tools
  static Point Str2Dim(string dim);
  static void ShowVectorOfMat(vector<Mat> codebook);
  static void SaveCodebook(vector<Mat> codebook, string dimensoes, int codebookSize);
  vector<Mat> OpenImages(vector<string> imagesList);
  void CompareVectorOfMat(vector<Mat> codebook1, vector<Mat> codebook2);
};

#endif // VECTORQUANTIZER_H
