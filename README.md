# VectorQuantizer-LBG

Quantizador vetorial com LBG para disciplina de Codificação Digital de Sinais, PGEA/UnB.

Uso:
-Para treinar (colocar imagens na pasta XXXXX)
./VectorQuantizer-LBG

- Para quantizar
./VectorQuantizer-LBG inputFile


ALGORITMO:
treinamento:

1 chutar vetor dos codebooks
2
3   Pegar todas as imagens
4   Segmentar essas imagens em vetores
5   Calcular a soma das diferenças absolutas (SDA) entre vetores das imagens (x) e o do codebook (y) Sum(|xn-yn|), n=1:vetor.size()
6   indexar vetores da imagem ao vetor do codebook de menor SDA.
7 calcular vetor médio de todos os vetores da imagem indexados por cada elemento do codebook
8 se vetor medio daquele vetor do codebook for diferente do vetor do codebook
9   subtitua o vetor do codebook
10 só parar quanto todos os vetores dos codebook não mudarem mais

Uso:
1 substituir o vetor de uma imagem pelo índice do vetor do codebook de menor SDA. codificar indices com huffman.

Extras:
calcula compressão
calcula distorção (MSE)

saida também codifica o codebook
tamanhoDoCodebookEmBytes = codebookSize * vectorSize * 1 (GRAY, se RGB = 3)
