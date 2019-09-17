#include "matrix.h"
// preencho todas as celulas cabeça
void initMatrix(int rows, int cols, Celula *init){
  int i, j;
  struct no temp*;
  temp = init->right;
  //preencho linhas-cabeça
  for(i = 0; i<rows; i++){
    if(i!=rows-1){
      temp-> right = (Apontador) malloc(sizeof(Celula));
      temp->i = -1;
      temp = temp->right;
    }
    else{
      temp->right = init;
    }
  }

  temp = init->below;
  //preencho colunas-cabeça
  for(i = 0; i<cols; i++){
    if(i!=cols-1){
      temp-> below = (Apontador) malloc(sizeof(Celula));
      temp->j = -1;
      temp = temp->below;
    }
    else{
      temp->below = init;
  }
}
