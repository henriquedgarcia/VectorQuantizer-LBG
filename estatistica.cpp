#include <iostream>
#include <opencv2/opencv.hpp>
#include "vectorquantizer.h"
#include <string>
#include <fstream>

using namespace std;
using namespace cv;

double Mse(Mat image1, Mat image2)
{
  int sum = 0;
  int difference = 0;
  double mse;
  
  assert((image1.size() == image2.size()));
  
  for(MatIterator_<uchar> it1 = image1.begin<uchar>(), it2 = image2.begin<uchar>();
      it1 != image1.end<uchar>();
      ++it1, ++it2)
    {      
      difference = *it1 - *it2;
      sum = sum + difference*difference;         
    }
  
      mse = ((double) sum) /(image1.cols * image1.rows);
      return mse;
}

int main(int argc, char **argv)
{
  vector<string> dimensoes = {"1x2","2x2","2x4","4x2","4x4"};
  vector<int> codebookSize; for (auto i = 16; i <= 2048; i+=16) codebookSize.push_back (i);
  VectorQuantizer quantizador;
  fstream check;
  for (int size : codebookSize)
    for (string dim : dimensoes)
      {
        string nome = "quantizado/imagem-" + dim + "-" + to_string(size) + ".tiff";
        check.open(nome);
          if(check.good())
            {
              check.clear();
              cout << "arquivo encontrado " << "quantizado/imagem-" + dim + "-" + to_string(size) + ".tiff, pulando.\n";
              check.close();
              continue;
            }
            else
            {
              cout << "OK\n";
              continue;
            }            
          check.close();
          
          
          double mse = Mse (imread ("imagens/lena.tiff",IMREAD_GRAYSCALE),
                              imread (nome,IMREAD_GRAYSCALE));
            cout << dim + "," + to_string(size) + "," + to_string(mse) << endl;
        
      }
  
	return 0;
}
