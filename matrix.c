#include "matrix.h"

void initMatrix(int rows, int cols, Celula *init){
  int i;
  struct no *atual = (PCelula) malloc(sizeof(Celula));
  atual = init->right;
  //preencho linhas-cabeça
  for(i = 0; i<rows; i++){
    if(i!=rows-1){
      atual-> below = (PCelula) malloc(sizeof(Celula));
      atual ->right = atual;
      atual->i = -1;
      atual = atual->below;
    }
    else{
      atual->below = init;
      atual->right = atual;
    }
  }

  atual = init;
  //preencho colunas-cabeça
  for(i = 0; i<cols; i++){
    if(i!=cols-1){
      atual-> right= (PCelula) malloc(sizeof(Celula));
      atual->j = -1;
      atual -> below = atual;
      atual = atual->right;
    }
    else{
      atual->right = init;
      atual->below = atual;
    }
  }
}

void readMatrix(){
  Row rows;
  Col cols;
  Item x;

  printf("Digite o número de linhas e o número de colunas separados por vírgula:\n");
  while(scanf("%d,%d", &rows, &cols), rows!=-1 && cols!=-1){

  }


}
