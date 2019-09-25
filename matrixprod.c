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

  //cria celula cabeça rows
  novo = M->init;
  for(i=1;i<=rows;i++){
      motherFunction(&atual , i, -1, 0, 0, 0, 0, 0);
      novo->below= atual;
      novo = novo->below;
      novo->below = M->init;
    }
  //cria celula cabeça cols
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
  PCelula iterador = init;
  for(i = 0; i<rows; i++){
    iterador = iterador->below;
    aux = iterador;
    auxLine = aux;
    if (aux->right != aux){
      printf("Cliente %d:\n", i+1);
      printf("--------------------------------\n");
      while(aux->right != auxLine){
        aux = aux->right;
        printf("Produto %d:\n", aux->j);
        printList(&(aux->x));
        printf("\n");
      }
      printf("--------------------------------\n");
    }
  }
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
void quantCPProduto(Matriz *M, Col cols){
  PCelula atual=M->init;
  PCelula aux;
  int quant=0;
  while(atual->j != cols){
    atual=atual->right;
  }
  aux=atual;
  atual = atual->below;
  while(atual->i != aux->i){
    quant+= sumOfProduct(&(atual->x));
    atual=atual->below;
  }
  printf("O Produto %d foi comprado %d vezes.\n",cols, quant);
}

void quantCPCliente(Matriz *M, Row rows){
  PCelula atual=M->init;
  PCelula aux;
  int quant=0;
  while(atual->i != rows){
    atual=atual->below;
  }
  aux=atual;
  atual = atual->right;
  while(atual->j != aux->j){
    quant+= sumOfClient(&(atual->x));
    atual=atual->right;
  }
  printf("O Cliente %d fez: %d compras.\n",rows, quant);
}
void delasocaMatriz(Matriz *M){
  Col j;
  PCelula atual = M->init;
  PCelula kill;
  PCelula atualLine;
  //desaloca itens
  for(j = 0; j< M->cols; j++){
    atual = atual->right;
    atualLine = atual;
    atual = atual->below;
    atualLine->below = atualLine;
    while(atual!= atualLine){
      kill = atual;
      atual = atual->below;
      clearList(&(kill->x));
      free(kill);
    }
  }
  //desaloca células-cabeça coluna
  atual = M->init;
  atual = atual->right;
  while(atual != M->init){
    kill = atual;
    atual = atual->right;
    free(kill);
  }
  //desaloca células-cabeça linha
  atual = M->init;
  atual = atual->below;
  while(atual != M->init){
    kill = atual;
    atual = atual->below;
    free(kill);
  }
  atual = M->init;
  atual->right = M->init;
  atual->below = M->init;
  M->rows = 0;
  M->cols = 0;
}
