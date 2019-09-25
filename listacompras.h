#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LISTACOMPRAS_H_
#define LISTACOMPRAS_H_

//definindo struct
typedef struct Cell* PCelulaP;

typedef struct Cell{
  int dia;
  int mes;
  int ano;
  int quant;
  PCelulaP next;
}CelulaP;

typedef struct Lista{
  PCelulaP first;
  PCelulaP last;
}ListaProd;

//definindo funções

void initList(ListaProd *lista);
void insertCompra(ListaProd *lista,int dia, int mes,int ano,int quant);
void printList(ListaProd *lista);
int sumOfProduct(ListaProd *lista);
void clearList(ListaProd *lista);
int sumOfClient(ListaProd *lista);


#endif
