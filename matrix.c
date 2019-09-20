#include "matrix.h"
#include "header.h"


void motherFunction(PCelula *son, Row row, Col col, Item x){
  (*son) = (PCelula) malloc(sizeof(Celula));
  (*son)-> i = row;
  (*son)-> j = col;
  (*son)-> x = x;
  (*son)-> right = *son;
  (*son)-> below = *son;
}


void initMatrix(Matriz *M, Row rows, Col cols){
  Row i;
  Col j;

  PCelula atual;
  PCelula novo;

  //creates mother cell

  motherFunction(&(M->init), -1, -1, 0);

  //cria celula cabeça linha
  novo = M->init;
  for(i=1;i<=rows;i++){
      motherFunction(&atual , i, -1, 0);
      novo->below= atual;
      novo = novo->below;
      novo->below = M->init;
    }
  //cria celula cabeça coluna
  novo = M->init;
  for (j=1 ; j<=cols ;j++){
      motherFunction(&atual, -1, j, 0);
      novo->right= atual;
      novo = novo->right;
      novo->right = M->init;
  }
}

void insertCell(Matriz *M, Row row, Col col, Item x){
  Row i;
  Col j;
  PCelula atual;
  PCelula novo;
  PCelula armazena;

  motherFunction(&novo, row, col, x);

  atual = M->init;
  for(i = 0; i<row; i++) atual = atual->below;
  armazena = atual;
  while(atual->right != armazena){
    atual = atual->right;
  }
  novo->right = armazena;
  atual->right = novo;

  atual = M->init;
  for(j = 0; j<col; j++) atual = atual->right;
  armazena = atual;
  while(atual->below != armazena){
    atual = atual->below;
  }
  novo->below = armazena;
  atual->below = novo;
}

void printMatrix(PCelula init, Row rows, Col cols){
  Row i;
  PCelula aux = init;
  PCelula auxLine;
  PCelula iterator= init;

  for(i = 0; i<rows; i++){
    iterator = iterator->below;
    aux = iterator;
    auxLine = aux;
    while(aux->right != auxLine){
      aux = aux->right;
      printf("%.2lf ", aux->x);
    }
    printf("\n");
  }
}



/*void printadaViolenta(PCelula init, Row rows, Col cols){
  Row i;
  PCelula aux = init;
  printf("%d %d %lf\n", aux->i, aux->j, aux->x);
  for(i = 0; i<rows; i++){
    aux = aux->below;
    printf("%d %d %lf\n", aux->i, aux->j, aux->x);
  }
  printf("%d %d %lf\n", aux->below->i, aux->below->j, aux->below->x);
  aux = init;
  for(i = 0; i<cols; i++){
    aux = aux->right;
    printf("%d %d %lf\n", aux->i, aux->j, aux->x);
  }
  printf("%d %d %lf\n", aux->right->i, aux->right->j, aux->right->x);
  printf("\n");
}
*/


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
