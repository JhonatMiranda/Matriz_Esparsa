#include "header.h"

void mainMenu(Matriz *M){
  Row rows;
  Col cols;
  Item x;
  int op = -1;
  char nomeArq[50];
  FILE *ptrFile;

  while(op){

    printf("Digite a operação desejada:\n");
    printf("1 - Receber matriz esparsa de um arquivo\n");
    printf("2 - Imprimir matriz esparsa\n");
    printf("0 - Sair do programa\n");
    scanf("%d", &op);

    switch(op){
      case 1:
        printf("\nDigite abaixo o seu arquivo \"[nome do arquivo].txt\":\n");
        scanf("%s", nomeArq);
        printf("\n");
        inputArquivo(M, ptrFile, nomeArq);
        break;
      case 2:
        printMatrix((*M).init , (*M).rows, (*M).cols);
        break;
      case 0:
        printf("\nPrograma Encerrado\n");
        return;
        break;
      default:
        printf("\nOperação inválida, digite outro número\n");
        break;
    }
  }
}
