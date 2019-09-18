#include "header.h"
#include "matrix.h"
void initMatrix(int rows,int cols,Matriz_Esparsa *M){
  int i,j;
  PCelula atual;
  //cria celula -1 e -1
  M->first= (PCelula) malloc(sizeof(Celula));
  M->first->i=-1;
  M->first->j=-1;
  M->first->right=M->first;
  M->first->below=M->first;
  M->lastrow=M->first;
  M->lastcol=M->first;
  printf("%d %d\n",M->first->i,M->first->j);
  //cria celula cabeça linha
  for (i=0;i<rows;i++){
      atual=(PCelula) malloc(sizeof(Celula));
      M->lastrow->below=atual;
      M->lastrow=M->lastrow->below;
      M->lastrow->i=-1;
      M->lastrow->j=i+1;
      M->lastrow->below=M->first;
      M->lastrow->right=M->lastrow;
      printf("%d %d\n",M->lastrow->i,M->lastrow->j);
  }
  //cria celula cabeça coluna
  for (j=0;j<cols;j++){
      atual=(PCelula) malloc(sizeof(Celula));
      M->lastcol->right=atual;
      M->lastcol=M->lastcol->right;
      M->lastcol->i=j+1;
      M->lastcol->j=-1;
      M->lastcol->below=M->lastcol;
      M->lastcol->right=M->first;
      printf("%d %d\n",M->lastcol->i,M->lastcol->j);
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
