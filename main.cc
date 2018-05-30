#include <iostream>
#include "vectorquantizer.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
  VectorQuantizer quantizador;
  //  vector<string> dimensoes = {"4x4"};
  vector<string> dimensoes = {"1x2","2x2","2x4","4x4"};
  vector<int> codebookSize = {256,512,1024,2048};
  vector<Mat> codebook;
  
  if(false)
    {
      // treinamento
      cout << "Registrando imagens para treinamento \n";
      vector<string> imagens;
      fstream saida;
      
      // imagens.push_back ("lena512gray.tiff");
      // imagens.push_back ("treinamento1.tiff");
      imagens.push_back ("treinamento2.tiff");
      imagens.push_back ("treinamento3.tiff");
      imagens.push_back ("treinamento4.tiff");
      
      cout << "Inicialando treinamento \n";
      for (auto size : codebookSize)
        for (auto dim : dimensoes)
          {
            cout << "treinamento para codebook = " << size << ", dimensões = " << dim << endl;
            codebook = quantizador.Train(imagens, dim, size);
            
            if(true)
              {
                cout << "codebook" << endl;
                for(uint i = 0; i < codebook.size (); i++)
                  {
                    cout << "(" << i << ")" << codebook[i] << " = \n";
                    //                    if (i%5 ==0)
                    //                      cout << endl;
                  }
              }
            
            cout << "gravando codebook" << endl;
            Point dimensao = quantizador.Str2Dim (dim);
            saida.open (string("saida-codebook-") + string(dim) + string("-") + to_string(size) + string(".bin"), ios::out|ios::binary);
            for(uint code = 0; code < codebook.size (); code++)
              for(int i = 0; i < dimensao.y; i++)
                for(int j = 0; j < dimensao.x; j++)
                  saida.put (codebook[code].at<uchar>(i,j));
            saida.close ();
            cout << "ok\n";
          }
    }
  
  if(true)
    {
      //      abrindo codebook
      fstream input;
      Mat image;
      image = imread("treinamento1.tiff",IMREAD_GRAYSCALE);      
      auto size = 256;
      auto dim = string("4x4");
      //      for (auto size : codebookSize)
      {
        //          for (auto dim : dimensoes)
        { 
          codebook = vector<Mat>(size);
          Point dimensao = quantizador.Str2Dim (dim);
          
          // input.open (string("saida-codebook-") + string(dim) + string("-") + to_string(size) + string(".bin"), ios::out|ios::binary);
          input.open ("codebook.bin", ios::in|ios::binary);
          assert(input.is_open ());
          
          for(uint code = 0; code < codebook.size (); code++)
            {
              codebook[code] = Mat(dimensao.y,dimensao.x,CV_8UC1);
              for(MatIterator_<uchar> it = codebook[code].begin<uchar>(); it != codebook[code].end<uchar>(); ++it)
                {
                  uchar caractere = input.get ();
                  *it = caractere;                  
                  cout << "pegou caractere " << dec << (int) caractere << endl;
                }
              
            }
//            for(int i = 0; i < dimensao.y; i++)
//              for(int j = 0; j < dimensao.x; j++)
//                {
//                  codebook[code] = Mat(dimensao.y,dimensao.x,CV_8UC1);
//                  uchar caractere;
//                  caractere = input.get ();
//                  
//                  codebook[code].at<uchar>(j,i) = caractere;
//                  cout << "guardou caractere " << hex << codebook[code].at<uchar>(j,i) << endl;
                  
//                }
          input.close ();
          
//          if(false) // Mostra codebook
            {
              cout << "codebook" << endl;
              for(uint i = 0; i < codebook.size (); i++)
                cout << "(" << i << ")\n" << codebook[i] << " = \n";
              cout << "saindo";
              exit(0);
            }
//          quantizador.Quantize (codebook,string("treinamento1.tiff"),dim,size);
          
          
          
        }
      }
    }
  
  return 0;
}

