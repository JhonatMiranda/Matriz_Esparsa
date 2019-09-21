#include "listacompras.h"
/*
int main(){
  ListaProd lista;
  char data[10];
  int quant,soma;
  initList(&lista);
  while(1){
    printf("Digite a quantidade comprada:\n");
    scanf("%d",&quant);
    if (quant==0)break;
    printf("Digite a data:\n");
    scanf("%s",data);
    insertCompra(&lista,data,quant);
  }
  printList(&lista);
  soma=sumOfQuant(&lista);
  clearList(&lista);
}
*/
//função inicia lista de produtos
void initList(ListaProd *lista){
  PCelulaP atual;
  lista->first=(PCelulaP) malloc(sizeof(CelulaP));
  lista->last=lista->first;
  atual=lista->first;
  atual->quant=0;
  atual->next=NULL;
}
//função insere lista de compra
void insertCompra(ListaProd *lista,char *data,int quant){
  PCelulaP atual=lista->last;
  PCelulaP novo=(PCelulaP) malloc(sizeof(CelulaP));
  while(atual->next != NULL) atual=atual->next;
  atual->next=novo;
  atual=atual->next;
  strcpy(atual->data,data);
  atual->quant=quant;
  atual->next=NULL;
}
//função printa a lista
void printList(ListaProd *lista){
  PCelulaP atual=lista->first;
  while(atual->next != NULL){
    atual=atual->next;
    printf("%s %d\n",atual->data,atual->quant);
  }
}
//função que retorna a soma da lista
int sumOfQuant(ListaProd *lista){
  int soma=0;
  PCelulaP atual=lista->first;
  while(atual->next != NULL){
    atual=atual->next;
    printf("%d\n",atual->quant);
    soma+=atual->quant;
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
