#include "header.h"

_Bool mainMenu(Lista *x){
  int op;
  printf("Digite a operação desejada:\n");
  printf("1- aaa\n");
  printf("2- bbb\n");
  printf("3- ccc\n");
  printf("0 - Sair do menu\n");
  scanf("%d", &op);

switch(op){
  case 1:
    return 0;
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    break;
  }
  return 1;
}
