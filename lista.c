#include "lista.h"

void listinsert(List *lista){
  lista->primeiro=(Apontador) malloc(sizeof(Celula));
  lista->ultimo=lista->primeiro;
  lista->primeiro->rigth=(&primeiro);
  lista->primeiro->below=(&primeiro);
  lista->primeiro->i=-1;
  lista->primeiro->j=-1;
}
