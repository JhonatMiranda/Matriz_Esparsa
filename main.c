
#include "matrix.h"


int main(){
  int col,linha,colin,linin;
  double item;
  int i;
  PCelula ponteiro;

  Matriz_Esparsa M;
  printf("Digite a quantidade de linhas e colunas da matriz:\n");
  scanf("%d %d",&col,&linha);
  initMatrix(linha,col,&M);
  printf("Digite a linha, coluna e o item para inserir:\n");
  scanf("%d %d %lf",&linin,&colin,&item);
  insertCel(linin,colin,item,&M);
  return 0;
}
