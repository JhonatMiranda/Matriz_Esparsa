#include "header.h"
#include "matrix.h"
void initMatrix(int rows, int cols, Matriz_Esparsa *M){
  int i;
  PCelula atual = (PCelula) malloc(sizeof(Celula));
  atual = M->init->below;
  //preencho linhas-cabeça
  for(i = 0; i<rows; ++i){
    if(i!=rows-1){
      atual-> below = (PCelula) malloc(sizeof(Celula));
      atual->i = -1;
      atual = atual->below;
    }
    else{
      atual->below = init;
      atual->right = atual;
    }
  }

  atual = init->right;
  //preencho colunas-cabeça
  for(i = 0; i<cols; ++i){
    if(i!=cols-1){
      atual-> right = (PCelula) malloc(sizeof(Celula));
      atual->j = -1;
      atual->below = atual;
      atual = atual->right;
    }
    else{
      atual->right = init;
      atual->below = atual;
    }
  }
}

//prototipo da função de leitura de matriz *sujeito a alterações
/*
void readMatrix(){
  FILE *arq;
  Row rows,rinsert;
  Col cols,cinsert;
  Celula init;
  arq=fopen("arquivo.txt","rt");
  fscanf(arq,"%d,%d",&rows,&cols);
  initMatrix(&init,rows,cols);
  fscanf(arq,"%d,%d,%f",&rinsert,&cinsert);
}
*/
