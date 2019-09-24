#include <stdio.h>
#include <stdlib.h>
#include "listacompras.h"

#ifndef MATRIXPROD_H_
#define MATRIXPROD_H_

typedef int Row;
typedef int Col;
typedef int Quant;
typedef ListaProd* Item;
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

  PCelula init;
  Row rows;
  Col cols;

}Matriz;

//iniciar todas as células cabeça
void motherFunction(PCelula *son, Row row, Col col, Data data, Quant quant);
void initMatrix(Matriz *M, Row rows, Col cols);
void insertCell(Matriz *M, Row row, Col col,int dia, int mes,int ano,Quant quant);
void printMatrix(PCelula init, Row rows, Col cols);
#endif
