#include <iostream>
#include "vectorquantizer.h"
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
  string name = "lena512gray.tiff";
  VectorQuantizer quantizador;
  if (argc == 1)
    {
      // treinamento
      vector<string> imagens;
      imagens.push_back ("imagem1.tiff");
      imagens.push_back ("imagem2.tiff");
      imagens.push_back ("imagem3.tiff");
      imagens.push_back ("imagem4.tiff");
      imagens.push_back ("imagem5.tiff");
      imagens.push_back ("imagem6.tiff");
      imagens.push_back ("imagem7.tiff");
      imagens.push_back ("imagem8.tiff");
      
      vector<vector<uchar>> codebook = quantizador.Train(imagens);
      
      // TODO: salvar codebook em arquivo aqui.
    }
  else
    {
      // codificação
      name = argv[1];
      
    }
  
  return 0;
}
