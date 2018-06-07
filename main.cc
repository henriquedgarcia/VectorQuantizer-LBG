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
  
  if(false)
    {
      // treinamento      
      vector<string> treinamento = {"imagens/teatro.tiff"};
      
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
  
  if(true)
    {
      // Quantização
      dimensoes = {"1x2"};
      codebookSize = {16};      
      
      // abrindo codebook
      for (int size : codebookSize)
        for (string dim : dimensoes)
          {
            string codebookfile = "codebooks/codebook-" + dim + "-" + to_string(size) + ".cdbk";
            codebook = VectorQuantizer::loadCodebook(codebookfile, dim, size);   
            
            // mostra codebook
            if(true) VectorQuantizer::ShowVectorOfMat(codebook);
            // Aplica codebook
//            quantizador.Quantize (codebook,string("treinamento1.tiff"),dim,size);
          }      
    }
  
  return 0;
}
