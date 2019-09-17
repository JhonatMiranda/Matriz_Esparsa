#include "matrix.h"

void initMatrix(int rows, int cols, Celula *init){
  int i;
  struct no *atual;
  atual = init->right;
  //preencho linhas-cabeça
  for(i = 0; i<rows; i++){
    if(i!=rows-1){
      atual-> right = (struct no*) malloc(sizeof(Celula));
      atual ->below = atual;
      atual->i = -1;
      atual = atual->right;
    }
    else{
      atual->right = init;
      atual->below = atual;
    }
  }

  atual = init->below;
  //preencho colunas-cabeça
  for(i = 0; i<cols; i++){
    if(i!=cols-1){
      atual-> below = (struct no*) malloc(sizeof(Celula));
      atual->j = -1;
      atual -> right = atual;
      atual = atual->below;
    }
    else{
      atual->below = init;
      atual->right = atual;
    }
  }
}
