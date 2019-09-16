#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_
#define LISTA_H_
//functions
void makeheadmain(List *lista);
void makeheadrow(List *lista);
void makeheadrow(List *lista);

//structs

typedef struct Knot *Apontador;
typedef int Row;
typedef int Col;
typedef int Item;

typedef struct Knot{
  struct Knot *right;
  struct Knot *below;
  Row i;
  Col j;
  Item x;
}Celula;

typedef struct Lista{
  Apontador primeiro;
  Apontador ultimo;
}List;







#endif
