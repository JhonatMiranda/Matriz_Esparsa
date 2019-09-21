#include <stdio.h>
#include <stdlib.h>
 int main() {
   FILE *ptrFile;
   char nomeArq[50];
   int rows,cols,cont;
   double value;
   cont=0;
   printf("Digite o nome do arquivo:" );
   scanf("%s",nomeArq );
   ptrFile=fopen(nomeArq,"r");
   while (!feof(ptrFile)) {
    if (cont==0){
      fscanf(ptrFile,"%d,%d",&rows,&cols);
      //Função init<--- AQUI
      printf("%d %d\n",rows,cols);
      cont++;
    }else{
      fscanf(ptrFile,"%d,%d,%lf",&rows,&cols,& value);
      if(value!=0.0){
        //Função de inserirCell <---AQUI
        printf("%d %d %.2f\n",rows,cols,value );
      }

    }
   }
   fclose(ptrFile);
   return 0;
 }
