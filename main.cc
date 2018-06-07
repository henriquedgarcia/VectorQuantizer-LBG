#include <iostream>
#include "vectorquantizer.h"
#include <string>
#include <fstream>

using namespace std;

// help funcions
vector<Mat> loadCodebook(string codebookfile, string dimensoes, int codebookSize);

int main()
{  
  vector<string> dimensoes = {"1x2","2x2","2x4","4x2","4x4"};
  vector<int> codebookSize; for (auto i = 16; i <= 2048; i+=16) codebookSize.push_back (i);
  VectorQuantizer quantizador;
  vector<Mat> codebook;
    vector<int> codebookSize = {16}; 
    
  if(true)
    {
      // treinamento      
      
      treinamento = {"imagens/teatro.tiff"};
      dimensoes = {"1x2"};
           

      cout << "Inicialando treinamento \n";
      for (int size : codebookSize)
        for (string dim : dimensoes)
          {
            cout << "treinamento para codebook = " << size << ", dimensões = " << dim << endl;
            codebook = quantizador.Train(treinamento, dim, size);

            // mostra codebook
            if(true) VectorQuantizer::ShowVectorOfMat(codebook);

            // Salva codebook
            VectorQuantizer::SaveCodebook(codebook, dim, size);
          }
    }

  if(false)
    {
      VectorQuantizer quantizador;
      // dimensoes = {"4x4"};
      dimensoes = {"1x2","2x2","2x4","4x4"};
      codebookSize = {256,512,1024,2048};
      vector<Mat> codebook;
      fstream input;

      //      abrindo codebook
      //      auto size = 256;
      //      auto dim = string("4x4");
      for (int size : codebookSize)
        {
          for (string dim : dimensoes)
            {
              codebook = vector<Mat>(size);
              Point dimensao = quantizador.Str2Dim (dim);
              input.open (string("saida-codebook-") + string(dim) + string("-") + to_string(size) + string(".bin"), ios::in|ios::binary);
              // input.open ("codebook.bin", ios::in|ios::binary);
              assert(input.is_open ());

              for(uint code = 0; code < codebook.size (); code++)
                {
                  codebook[code] = Mat(dimensao.y,dimensao.x,CV_8UC1);
                  for(MatIterator_<uchar> it = codebook[code].begin<uchar>(); it != codebook[code].end<uchar>(); ++it)
                    {
                      int caractere = input.get ();
                      if(caractere == EOF) exit(-1);
                      *it = (uchar) caractere;
                      //                  cout << "pegou caractere " << dec << (int) caractere << endl;
                    }
                }
              input.close ();

              if(false) // Mostra codebook
                {
                  cout << "codebook" << endl;
                  for(uint i = 0; i < codebook.size (); i++)
                    cout << "(" << i << ")\n" << codebook[i] << " = \n";
                  cout << "saindo";
                  // exit(0);
                }
              quantizador.Quantize (codebook,string("treinamento1.tiff"),dim,size);
            }
        }
    }

  return 0;
}
