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
  
  if(true)
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
          }
    }
  
  if(false)
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
          input.open ("codebook.bin", ios::out|ios::binary);
          
          for(uint code = 0; code < codebook.size (); code++)
            for(int i = 0; i < dimensao.y; i++)
              for(int j = 0; j < dimensao.x; j++)
                {
                  char caractere;
                  input.get (caractere);
                  codebook[code].at<uchar>(i,j) = caractere;
                }
          input.close ();
          
          if(true) // Mostra codebook
            {
              cout << "codebook" << endl;
              for(uint i = 0; i < codebook.size (); i++)
                cout << "(" << i << ")" << codebook[i] << " = \n";
            }
          quantizador.Quantize (codebook,string("treinamento1.tiff"),dim,size);
          
          
          
        }
      }
    }
  
  return 0;
}

