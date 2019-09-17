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
void initMatrix(int rows, int cols, Celula *init);


//struct para matriz esparsa(sujeito a alterações)
typedef struct{

  Celula init;

}Matriz_Esparsa;

typedef struct Lista{
  Apontador Primeiro;
  Apontador Ultimo;
}List;


#endif
