#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LISTACOMPRAS_H_
#define LISTACOMPRAS_H_

//definindo struct
typedef struct Cel* PCelulaP;

typedef struct Cel{
  char  data[10];
  int quant;
  PCelulaP next;
}CelulaP;

typedef struct Lista{
  PCelulaP first;
  PCelulaP last;
}ListaProd;

//definindo funções

void initList(ListaProd *lista);
void insertCompra(ListaProd *lista,char *data,int quant);
void printList(ListaProd *lista);
int sumOfQuant(ListaProd *lista);
void clearList(ListaProd *lista);


#endif
