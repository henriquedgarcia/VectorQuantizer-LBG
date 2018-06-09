#include <iostream>
#include "vectorquantizer.h"
#include <string>
#include <fstream>

using namespace std;

// help funcions

int main()
{  
  vector<string> dimensoes = {"1x2","2x2","2x4","4x2","4x4"};
  vector<int> codebookSize; for (auto i = 16; i <= 2048; i+=16) codebookSize.push_back (i);
  VectorQuantizer quantizador;
  vector<Mat> codebook;    
  
  if(false)
    {
      // treinamento      
      vector<string> treinamento = {"imagens/teatro.tiff"};
      
      cout << "Inicialando treinamento \n";
      for (string dim : dimensoes)
        for (int size : codebookSize)
          {
            cout << "treinamento para codebook = " << size << ", dimensões = " << dim << endl;
            codebook = quantizador.Train(treinamento, dim, size);
            
            // mostra codebook
            if(true) VectorQuantizer::ShowVectorOfMat(codebook);
            
            // Salva codebook
            VectorQuantizer::SaveCodebook(codebook, dim, size);
          }
    }
  
  if(true)
    {
      // Quantização
      dimensoes = {"1x2"};
      codebookSize = {176};      
      
      // abrindo codebook
      for (string dim : dimensoes)
        for (int size : codebookSize)
          {
            string codebookfile = "codebooks/codebook-" + dim + "-" + to_string(size) + ".cdbk";
            codebook = VectorQuantizer::loadCodebook(codebookfile, dim, size);   
            
            // mostra codebook
            if(false) VectorQuantizer::ShowVectorOfMat(codebook);
            // Aplica codebook
            string saida = quantizador.Quantize (codebook,string("imagens/lena.tiff"),dim,size);
            cout << saida << endl;
          }      
    }
  
  return 0;
}
