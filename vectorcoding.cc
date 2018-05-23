#include "vectorcoding.h"

using namespace std;

string tamanho = "1x2";

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

void VectorQuantizer::Quantize(string nameInput)
{
  OpenImage (nameInput);
  Vectorize ();
}

void VectorQuantizer::OpenImage(string NameInput)
{
  m_image = imread(NameInput, IMREAD_GRAYSCALE);
  if ( !m_image.data )
    {
      cout << "No image data \n";
      exit(-1);
    }
//  namedWindow("Display Image", WINDOW_AUTOSIZE );
//  imshow("Display Image", m_image);
//  waitKey();
}

//vector<Mat *> VectorQuantizer::Vectorize(Mat imgInput)
vector<Mat *> VectorQuantizer::Vectorize(void)
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
