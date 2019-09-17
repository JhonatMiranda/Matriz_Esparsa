#include "lista.h"
//cria celula cabeça principal, com indice -1 e -1
void makeheadmain(List *lista){
  lista->primeiro=(Apontador) malloc(sizeof(Celula));
  lista->primeiro->right=lista->primeiro;
  lista->primeiro->below=lista->primeiro;
  lista->ultimo=lista->primeiro;
  lista->primeiro->i=-1;
  lista->primeiro->j=-1;
}
//cria celula cabeça de lista de linhas com indice da linha -1
void makeheadrow(List *lista){
  lista->ultimo->below=(Apontador) malloc(sizeof(Celula));
  lista->ultimo=lista->ultimo->below;
  lista->ultimo->below=lista->primeiro;
  lista->ultimo->below->i=-1;
}
//cria celula cabeça de lista de coluna com indice da coluna -1
void makeheadcol(List *lista){
  lista->ultimo->right=(Apontador) malloc(sizeof(Celula));
  lista->ultimo=lista->ultimo->right;
  lista->ultimo->right=lista->primeiro;
  lista->ultimo->below->j=-1;
}

// preencho todas as celulas cabeça
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
