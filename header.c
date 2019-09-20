#include "header.h"
#include "matrix.h"

int mainMenu(Matriz *M){
  Row rows;
  Col cols;
  Item x;
  int op;

  printf("Digite a operação desejada:\n");
  printf("1 - Inicializar matriz esparsa\n");
  printf("2 - Inserir item na matriz esparsa\n");
  printf("3 - Imprimir matriz esparsa\n");
  printf("0 - Sair do programa\n");
  scanf("%d", &op);

switch(op){
  case 1:
    printf("\nDigite abaixo o número de linhas que deseja ter em sua matriz:\n");
    scanf("%d", &rows);
    printf("Digite abaixo o número de colunas que deseja ter em sua matriz:\n");
    scanf("%d", &cols);
    printf("\n");
    initMatrix(M, rows, cols);
    break;
  case 2:
    printf("\nDigite abaixo a linha em que deseja inserir o item:\n");
    scanf("%d", &rows);
    printf("Digite abaixo a coluna em que deseja inserir o item:\n");
    scanf("%d", &cols);
    printf("Digite abaixo o valor do item em que deseja inserir:\n");
    scanf("%d", &x);
    printf("\n");
    insertCell(M, rows, cols, x);
    break;
  case 3:
    printMatrix((*M).init , (*M).rows);
    break;
  case 0:
    return 0;
    break;
  default:
    break;
  }
  return 1;
}
