
#include "matrix.h"

void initMatrix(int rows,int cols,Matriz_Esparsa *M){
  int i;
  PCelula atual;
  //cria celula -1 e -1
  M->first= (PCelula) malloc(sizeof(Celula));
  printf("+1\n");
  M->first->i=-1;
  M->first->j=-1;
  M->first->right=M->first;
  M->first->below=M->first;
  M->lastrow=M->first;
  M->lastcol=M->first;
  //cria celula cabeça linha
  for (i=0;i<rows;i++){
    if(i<rows-1){
      atual= (PCelula) malloc(sizeof(Celula));
      printf("+1\n");
      M->lastrow=atual;
      M->lastrow->i=-1;
      M->lastrow->j=i+1;
      M->lastrow->below=M->first;
      M->lastrow->right=M->lastrow;
    }
    else{
      atual= (PCelula) malloc(sizeof(Celula));
      printf("+1\n");
      M->lastrow = atual;
      M->lastrow->i=-1;
      M->lastrow->j=i+1;
      M->lastrow->below=M->first;
      M->lastrow->right=M->lastrow;
    }
  }
  for (i=0;i<cols;i++){
    if (i<cols-1){
      atual=(PCelula) malloc(sizeof(Celula));
      printf("+1\n");
      M->lastcol=atual;
      M->lastcol->j=-1;
      M->lastrow->i=i+1;
      M->lastcol->below=M->lastcol;
      M->lastcol->right=M->first;
    }
    else{
      atual= (PCelula) malloc(sizeof(Celula));
      printf("+1\n");
      M->lastcol=atual;
      M->lastcol->j=-1;
      M->lastrow->i=i+1;
      M->lastcol->below=M->lastcol;
      M->lastcol->right=M->first;
    }
  }
}
void printMatrix(int linha,int col,Matriz_Esparsa *M){
    int i;
    PCelula atual = M->first->below;
    for (i=0;i<linha;i++){
      printf("%d %d\n",atual->i,atual->j);
      atual=atual->below;
    }
    atual= M->first->right;
    for (i=0; i<col;i++){
      printf("%d %d\n",atual->i,atual->j);
      atual=atual->right;
    }
}

int main(){
  int col,linha;
  Matriz_Esparsa M;
  scanf("%d %d",&col,&linha);
  initMatrix(linha,col,&M);
  printMatrix(linha,col,&M);
  return 0;
}
