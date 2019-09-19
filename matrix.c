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
void insertCel(int row,int col,double Item, Matriz_Esparsa *M){
    int i,j,k,l;
    PCelula atual=M->first;
    PCelula inicio;
    PCelula novo = (PCelula) malloc(sizeof(Celula));
    for (i=0;i<=row;i++){
      if (atual->j != row){
        atual=atual->below;
      }
      else{
        inicio=atual;
        atual->right=novo;
        atual=atual->right;
        atual->i=row;
        atual->x=Item;
        atual->right=inicio;
        atual->below=atual;
      }
    }
    atual=M->first;
    for (j=0;j<=col;j++){
      if(atual->i != col){
        atual=atual->right;
      }
      else{
        inicio=atual;
        atual->below=novo;
        atual=atual->below;
        atual->j=col;
        atual->below=inicio;
      }
    }
}
/*//prototipo de funçao de exibição da matriz *sujeito a alterações
void printMatriz(Matriz_Esparsa *M){
  atual=M->first;
  for (k=0;k<=col;k++){
    if (atual->i != col){
      atual=atual->right;
    }
    else{
      for (l=0;l<=row;l++){
        if (atual->i != row){
          atual=atual->below;
        }
        else{
          printf("%d %d %lf\n",atual->i,atual->j,atual->x);
        }
      }
    }
  }
}
/*
//prototipo da função de leitura de matriz *sujeito a alterações
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
