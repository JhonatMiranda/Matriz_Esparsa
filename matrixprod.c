#include "matrixprod.h"

void motherFunction(PCelula *son, Row row, Col col,int dia, int mes,int ano, Quant quant){
  (*son) = (PCelula) malloc(sizeof(Celula));
  (*son)-> i = row;
  (*son)-> j = col;
  (*son)-> x = insertCompra((*son)->x, &data, quant);
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

  motherFunction(&(M->init), -1, -1, 0, 0);

  //cria celula cabeça linha
  novo = M->init;
  for(i=1;i<=rows;i++){
      motherFunction(&atual , i, -1, 0, 0);
      novo->below= atual;
      novo = novo->below;
      novo->below = M->init;
    }
  //cria celula cabeça coluna
  novo = M->init;
  for (j=1 ; j<=cols ;j++){
      motherFunction(&atual, -1, j, 0, 0);
      novo->right= atual;
      novo = novo->right;
      novo->right = M->init;
  }
}
void insertCell(Matriz *M, Row row, Col col,Data data,Quant quant){
  Row i;
  Col j;
  PCelula atual;
  PCelula novo;
  PCelula armazena;

  motherFunction(&novo, row, col, data, quant);

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
  int deltaLeft, deltaRight;

  for(i = 0; i<rows; i++){
    iterador = iterador->below;
    aux = iterador;
    auxLine = aux;

    if(aux->right == auxLine){
      for(j =0; j<cols; j++) printf("0.00 ");
    }
    else{
      if(aux->right->j != 1 && aux->right->j != -1){
        deltaLeft = aux->right->j - 1;
        for(j=0; j<deltaLeft; j++) printf("0.00 ");
      }
      while(aux->right != auxLine){
        aux = aux->right;
        printf("%.2lf ", aux->x);
        if(aux->right->j == -1){
          deltaRight = abs(cols - aux->j);
          for(j=0; j<deltaRight; j++) printf("0.00 ");
        }
        if(aux->right->j != (aux->j)+1 && aux->right->j != -1){
          deltaRight = abs(aux->right->j - aux->j) - 1;
          for(j=0; j<deltaRight; j++) printf("0.00 ");
        }
      }
    }
    printf("\n");
  }
  printf("\n");
}
