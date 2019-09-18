#include <stdio.h>
#include <stdlib.h>


#ifndef MATRIX_H_
#define MATRIX_H_

typedef int Row;
typedef int Col;
typedef double Item;
typedef struct no* PCelula;

//struct para criar celulas
typedef struct no{
  PCelula right;
  PCelula below;
  Row i;
  Col j;
  Item x;
}Celula;

//struct para matriz esparsa(sujeito a alterações)
typedef struct{

  PCelula first;
  PCelula lastcol;
  PCelula lastrow;

}Matriz_Esparsa;

//iniciar todas as células cabeça
void initMatrix(int rows,int cols,Matriz_Esparsa *M);
#endif
