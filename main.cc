#include <iostream>
#include "vectorquantizer.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  VectorQuantizer quantizador;
  
  if (argc == 1)
    {
      // treinamento
      cout << "Registrando imagens para treinamento \n";
      vector<string> imagens;
      imagens.push_back ("treinamento1.tiff");
      imagens.push_back ("treinamento2.tiff");
      imagens.push_back ("treinamento3.tiff");
      imagens.push_back ("treinamento4.tiff");
      
      cout << "ajustando parametros" << endl;      
      vector<string> dimensoes = {"1x2","2x2","2x3","2x4","4x4"};
      vector<int> codebookSize = {256,512,1024,2048};
      fstream saida;
      
      cout << "Inicialando treinamento \n";
      for (auto size : codebookSize)
        for (auto dim : dimensoes)
          {
            cout << "treinamento para codebook = " << size << ", dimensões = " << dim << endl;
            vector<Mat> codebook = quantizador.Train(imagens, dim, size);
            
            if(true)
              {
                for(uint i = 0; i < codebook.size (); i++)
                  cout << "codebook[" << i << "] = " << codebook[i] << ", ";
                // exit(0);
              }
            
            cout << "gravando codebook" << endl;
            
            saida.open (string("saida-codebook-") + string(dim) + string(".bin"), ios::out|ios::binary);
            for(uint code = 0; code < codebook.size (); code++)
              for(uint i = 0; i < 1; i++)
                for(uint j = 0; j < 2; j++)
                  saida.put (codebook[code].at<uchar>(i,j));
            saida.close ();
          }
      
      
      //      quantizador.Quantize (codebook,image,dim,codebookSize);
      // TODO: salvar codebook em arquivo aqui.
    }
  else
    {
      // codificação
      string name (argv[1]);
      cout << name << endl;
      
    }
  
  return 0;
}
