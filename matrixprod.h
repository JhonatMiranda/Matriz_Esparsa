#include <stdio.h>
#include <stdlib.h>
#include "listacompras.h"

#ifndef MATRIXPROD_H_
#define MATRIXPROD_H_

typedef int Row;
typedef int Col;
typedef int Quant;
typedef ListaProd Item;
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
void inputArquivo(Matriz *M, FILE *ptrFile, char nomeArq[]);
void motherFunction(PCelula *son, Row row, Col col,int dia, int mes,int ano, Quant quant,int *cont);
void initMatrix(Matriz *M, Row rows, Col cols);
void insertCell(Matriz *M, Row row, Col col,int dia, int mes,int ano,Quant quant,int *cont);
void printMatrix(PCelula init, Row rows, Col cols);
void quantCPProduto(Matriz *M, Col cols);
void quantCPCliente(Matriz *M, Row rows);
void delasocaMatriz(Matriz *M);
#endif
