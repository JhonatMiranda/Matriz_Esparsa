#include "matrix.h"
#include "header.h"

int main(){
  FILE *ptrFile;
  char nomeArq[50];
  Row rows;
  Col cols;
  Item x;
  Matriz M;
  int menu;
  int cont;
  cont=0;
  menu=-1;

  while(menu!=0){
    if (menu==1){
      printf("Digite o nome do arquivo:" );
      scanf("%s",nomeArq );
      ptrFile=fopen(nomeArq,"r");
      while (!feof(ptrFile)) {
          if (cont==0){
            fscanf(ptrFile,"%d,%d",&rows,&cols);
            initMatrix(&M,rows,cols);
            cont++;
            }else{
              fscanf(ptrFile,"%d,%d,%lf",&rows,&cols,& x);
              if(x!=0.0){
               insertCell(&M,rows,cols,x);
             }

         }
      }
      fclose(ptrFile);
    }else if(menu==2){
      printMatrix(M.init,rows);
    }
    menu=mainMenu();
  }
  printf("PROGRAMA ENCERRADO\n" );
  return 0;
}
