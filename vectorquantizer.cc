#include "vectorquantizer.h"

using namespace std;

VectorQuantizer::VectorQuantizer() :
  m_tamanho ("1x2"),
  m_codeBookSize (256),
  codeBook (vector<vector*> (m_codeBookSize))
{}

VectorQuantizer::VectorQuantizer(string tamanho, int codeBookSize)
{
  m_tamanho = "1x2";
  m_codeBookSize = codeBookSize;
  codeBook = vector<vector*> (m_codeBookSize);
}

vector<vector<uchar> > VectorQuantizer::Train(vector<string> imagens)
{
  //  1 chutar vetor dos codebooks
  //  2 Nquanto houver imagem
  //  3   Pegar uas imagens
  //  4   Segmentar essas imagens em vetores
  //  5 Calcular a soma das diferenças absolutas (SDA) entre vetores das imagens (x) e o do codebook (y) Sum(|xn-yn|), n=1:vetor.size()
  //  6 indexar vetores da imagem ao vetor do codebook de menor SDA.
  //  7 calcular vetor médio de todos os vetores da imagem indexados por cada elemento do codebook
  //  8 se vetor medio daquele vetor do codebook for diferente do vetor do codebook
  //  9   subtitua o vetor do codebook
  //  10 só parar quanto todos os vetores dos codebook não mudarem mais
  
  //  for (i = 0; i < imagens.size (); i++)
  Mat img;
  vector<Mat> vectorBucket;
  auto it = vec.begin();
  for (auto nameInput : imagens)
    {
      Mat img = OpenImage (nameInput);      
      vector<Mat> vetores = Vectorize (img);
      vectorBucket.insert (vectorBucket.end(),vetores.begin(), vetores.end());
    }
//  Sum of absolute differences (SAD)
}

void VectorQuantizer::Quantize(string nameInput)
{
  
}

Mat VectorQuantizer::OpenImage(string NameInput)
{
  
  image = imread(NameInput, IMREAD_GRAYSCALE);
  if ( !m_image.data )
    {
      cout << "No image data \n";
      exit(-1);
    }
  //  namedWindow("Display Image", WINDOW_AUTOSIZE );
  //  imshow("Display Image", m_image);
  //  waitKey();
  return image;
}

//vector<Mat *> VectorQuantizer::Vectorize(Mat imgInput)
vector<Mat> VectorQuantizer::Vectorize(Mat imagem)
{
  int linha = 100;
  int coluna = 200;
  Mat vetor;
  
  for (int i = 0; i < m_image.rows; i += linha)
    for (int j = 0; j < m_image.cols ; j += coluna)
      {
        vetor = Mat(A, Rect(i, j, linha, coluna) );
        
        namedWindow("Display Image", WINDOW_AUTOSIZE);
        imshow("Display Image", vetor);
        waitKey();
      }
  
  
}

//void VectorCoding::Vectorize()
//{
//  linha=vt/384;
//  coluna = vt % 384;

//  for (px = 0; px < 15; px ++)
//  {
//  x = coluna *  4 + px / 4 ;
//  y = l i n h a *
//  4 + px%4;
//  u n i d im e n s i o n a l = y*
//  1536 + x ;
//  i f ( s e nt i d o == IMAGEM_PARA_VETOR)
//  v et o r . p i x e l [ px ] = img [ u n i d im e n s i o n a l ] ;
//  else
//  img [ u n i d im e n s i o n a l ] = v et o r . p i x e l [ px ] ;
//  }
//}
