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
  vector<vector<uchar>> m_codeBook;
  vector<Mat> m_images;
  vector<Mat *> m_imagesVectors;
  string m_vectorSize;
  fstream m_inputImage;
  int m_codeBookSize;

  VectorQuantizer();
  
  // Treinamento
  vector<vector<uchar>> Train(vector<string> imagens);
  // Transformar imagens em  vetores
  vector<Mat> Vectorize(Mat imagem);
  
  Mat OpenImage(string NameInput);
  
  // Depois que o codebook já foi feito, quantiza-se
  void Quantize(string nameInput);
  
};

#endif // VECTORQUANTIZER_H

#ifndef VECTORCODING_H
#define VECTORCODING_H



#endif // VECTORCODING_H
