#ifndef VECTORCODING_H
#define VECTORCODING_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

class VectorQuantizer
{
public:
  vector<vector*> m_codeBook;
  string m_tamanho;
  fstream m_inputImage;
  int m_codeBookSize;

  VectorQuantizer();
  void Quantize(string nameInput);
  vector<Mat *> Vectorize(void);
  void OpenImage(string NameInput);

};

#endif // VECTORCODING_H
