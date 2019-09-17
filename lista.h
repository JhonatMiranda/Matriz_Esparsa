#include <stdio.h>
#include <stdlib.h>

#ifndef MATRIX_H_
#define MATRIX_H_

typedef int Row;
typedef int Col;
typedef double Item;
typedef struct no* Apontador;

typedef struct no{
  struct no *right;
  struct no *below;
  Row i;
  Col j;
  Item x;
}Celula;

//iniciar todas as células cabeça
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

//struct para matriz esparsa(sujeito a alterações)
typedef struct{

  Celula init;

}Matriz_Esparsa;

typedef struct Lista{
  Apontador Primeiro;
  Apontador Ultimo;
}List;


#endif
