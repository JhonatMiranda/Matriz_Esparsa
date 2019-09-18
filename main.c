
#include "matrix.h"


int main(){
  int col,linha;
  Matriz_Esparsa M;
  scanf("%d %d",&col,&linha);
  initMatrix(linha,col,&M);
  return 0;
}
