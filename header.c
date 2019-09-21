#include "header.h"
#include "matrix.h"

int mainMenu(){
  int op;
  printf("Digite a operação desejada:\n");
  printf("1 - Inserir item na matriz esparsa\n");
  printf("2 - Imprimir matriz esparsa\n");
  printf("0 - Sair do programa\n");
  scanf("%d", &op);

if(op==1){

  return 1;

}else if(op==2){

  return 2;

}else if(op==0){

  return 0;

}else{
  printf("Opção inválida, escolha novamente.\n" );
  mainMenu();
  }
}
