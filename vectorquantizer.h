#ifndef VECTORQUANTIZER_H
#define VECTORQUANTIZER_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

class VectorQuantizer
{
public:
  vector<vector<uchar>> m_codeBook (m_codeBookSize);
  int m_codeBookSize = 256;
  string m_vectorSize = "1x2";
  vector<Mat> m_images;
  vector<Mat *> m_imagesVectors;
  
  fstream m_inputImage;

  VectorQuantizer();
  
  // Treinamento
  vector<vector<uchar>> Train(vector<string> imagens, string dim);
  // Transformar imagens em  vetores
  vector<Mat> Vectorize(vector<Mat> images, string dim);
  vector<Mat> Vectorize(Mat imagem, string dim);

  Mat OpenImage(string NameInput);

  // Depois que o codebook já foi feito, quantiza-se
  void Quantize(string nameInput);
  Point Str2Dim(string dim);
  
};

#endif // VECTORQUANTIZER_H

#ifndef VECTORCODING_H
#define VECTORCODING_H



#endif // VECTORCODING_H
