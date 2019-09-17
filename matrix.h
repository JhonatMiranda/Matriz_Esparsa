#include <stdio.h>
#include <stdlib.h>

#ifndef MATRIX_H_
#define MATRIX_H_

typedef int Row;
typedef int Col;
typedef double Item;
typedef struct no* PCelula;

typedef struct no{
  struct no *right;
  struct no *below;
  Row i;
  Col j;
  Item x;
}Celula;

//iniciar todas as células cabeça
void initMatrix(Row rows, Col cols, Celula *init);

void readMatrix();


//struct para matriz esparsa(sujeito a alterações)
typedef struct{

  Celula init;

}Matriz_Esparsa;

#endif
