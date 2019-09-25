#include "listacompras.h"
//função inicia lista de produtos
void initList(ListaProd *lista){
  PCelulaP atual=(PCelulaP) malloc(sizeof(CelulaP));
  lista->last=atual;
  lista->first=atual;
  atual->quant=0;
  atual->next=NULL;
}
//função insere lista de compra
void insertCompra(ListaProd *lista,int dia, int mes,int ano,int quant){
  PCelulaP atual=lista->last;
  PCelulaP novo=(PCelulaP) malloc(sizeof(CelulaP));
  novo->dia=dia;
  novo->mes=mes;
  novo->ano=ano;
  novo->quant=quant;
  novo->next=NULL;
  atual->next=novo;
  lista->last=novo;
}
//função printa a lista
void printList(ListaProd *lista){
  PCelulaP atual=lista->first;
  while(atual->next != NULL){
    atual=atual->next;
    printf("%d/%d/%d  %d\n",atual->dia,atual->mes,atual->ano,atual->quant);
  }
}
//função que retorna a soma da lista
int sumOfProduct(ListaProd *lista){
  int soma=0;
  PCelulaP atual=lista->first;
  while(atual != NULL){
    soma += atual -> quant;
    atual = atual->next;
  }
  return soma;
}

int sumOfClient(ListaProd *lista){
  int soma=0;
  PCelulaP atual=lista->first;
  atual = atual->next;
  while(atual != NULL){
    soma++;
    atual = atual->next;
  }
  return soma;
}

//função que libera a lista
void clearList(ListaProd *lista){
  PCelulaP apagar;
  PCelulaP atual=lista->first;
  while(atual != NULL){
    apagar=atual;
    atual=atual->next;
    free(apagar);
  }
  lista->first=NULL;
  lista->last=NULL;
}
