#include "matrix.h"

void initMatrix(int rows, int cols, Celula *init){
  int i;
  struct no *temp;
  temp = init->right;
  //preencho linhas-cabeça
  for(i = 0; i<rows; i++){
    if(i!=rows-1){
      temp-> right = (struct no*) malloc(sizeof(Celula));
      temp ->below = temp;
      temp->i = -1;
      temp = temp->right;
    }
    else{
      temp->right = init;
      temp->below = temp;
    }
  }

  temp = init->below;
  //preencho colunas-cabeça
  for(i = 0; i<cols; i++){
    if(i!=cols-1){
      temp-> below = (struct no*) malloc(sizeof(Celula));
      temp->j = -1;
      temp -> right = temp;
      temp = temp->below;
    }
    else{
      temp->below = init;
      temp->right = temp;
    }
  }
}
