#include "matrixprod.h"

void motherFunction(PCelula *son, Row row, Col col, int dia, int mes, int ano, Quant quant, int *cont){
  ListaProd compra;
  initList(&compra);
  (*son) = (PCelula) malloc(sizeof(Celula));
  (*son)-> i = row;
  (*son)-> j = col;
  insertCompra(&compra, dia, mes, ano, quant);
  (*son)-> x = compra;
  (*son)-> right = *son;
  (*son)-> below = *son;
}


void initMatrix(Matriz *M, Row rows, Col cols){
  Col j;
  Row i;

  M->rows = rows;
  M->cols = cols;

  PCelula atual;
  PCelula novo;

  //creates mother cell

  motherFunction(&(M->init), -1, -1, 0, 0, 0, 0, 0);

  //cria celula cabeça linha
  novo = M->init;
  for(i=1;i<=rows;i++){
      motherFunction(&atual , i, -1, 0, 0, 0, 0, 0);
      novo->below= atual;
      novo = novo->below;
      novo->below = M->init;
    }
  //cria celula cabeça coluna
  novo = M->init;
  for (j=1 ; j<=cols ;j++){
      motherFunction(&atual, -1, j, 0, 0, 0, 0, 0);
      novo->right= atual;
      novo = novo->right;
      novo->right = M->init;
  }
}
void insertCell(Matriz *M, Row row, Col col,int dia,int mes,int ano,Quant quant,int *cont){
  Row i;
  Col j;
  PCelula atual;
  PCelula novo;
  PCelula armazena;
  motherFunction(&novo, row, col, dia, mes, ano, quant, cont);
  atual = M->init;
  for(i = 0; i<row; i++) atual = atual->below;
  armazena = atual;
  while(atual->right != armazena){
    atual = atual->right;
  }
  novo->right = armazena;
  atual->right = novo;

  atual = M->init;
  for(j = 0; j<col; j++) atual = atual->right;
  armazena = atual;
  while(atual->below != armazena){
    atual = atual->below;
  }
  novo->below = armazena;
  atual->below = novo;
}

void printMatrix(PCelula init, Row rows, Col cols){
  Row i;
  Col j;
  PCelula aux = init;
  PCelula auxLine;
  PCelula iterador= init;

  for(i = 0; i<rows; i++){
    iterador = iterador->below;
    aux = iterador;
    auxLine = aux;

    printf("Produto %d:\n\n", i+1);
    while(aux->right != auxLine){
      aux = aux->right;
      printf("Cliente %d:\n", aux->i);
      printList(&(aux->x));
      printf("\n");
    }
    printf("--------------------------------\n");
  }
  printf("\n");
}

void inputArquivo(Matriz *M, FILE *ptrFile, char nomeArq[]){
  int cont=0,cont2=0;
  Row rows;
  Col cols;
  Row rowant=0;
  Col colant=0;
  int x;
  char aux;
  int dia;
  int mes;
  int ano;

  ptrFile=fopen(nomeArq,"r");
  if(ptrFile==NULL){
    printf("ARQUIVO NÃO ENCONTRADO.\n" );
  }else{
    while(!feof(ptrFile)) {
      if (cont==0){
        fscanf(ptrFile, "%d,%d", &rows, &cols);
        initMatrix(M, rows, cols);
        cont++;
      }else{
        fscanf(ptrFile, "%d,%d%c" ,&rows ,&cols,&aux);
        if (rowant == rows && colant == cols) break;
        else{
          rowant=rows;
          colant=cols;
        }
        while(aux != 10){
          fscanf(ptrFile,"%d/%d/%d %d%c",&dia,&mes,&ano,&x,&aux);
          if(x!=0){
            insertCell(M, rows, cols, dia, mes, ano, x, &cont2);
          }
        }
      }
    }
    fclose(ptrFile);
  }
}
void quantCPProduto(Matriz *M,Row linha){
  PCelula atual=M->init;
  PCelula aux;
  int quant=0;
  while(atual->below->i != linha){
    atual=atual->below;
  }
  aux=atual;
  while(atual->right->j != aux->j ){
    atual=atual->right;
    quant=sumOfQuant(&(atual->x));
  }
  printf("%d\n",quant);
}
