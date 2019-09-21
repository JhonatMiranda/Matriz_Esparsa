#include <stdio.h>
#include <stdlib.h>
 int main() {
   FILE *ptrFile;
   char nomeArq[50];
   int rowls,cols,cont;
   double value;
   cont=0;
   printf("Digite o nome do arquivo:" );
   scanf("%s",nomeArq );
   ptrFile=fopen(nomeArq,"r");
   while (!feof(ptrFile)) {
    if (cont==0){
      fscanf(ptrFile,"%d,%d",&rowls,&cols);
      //Função init<--- AQUI
      printf("%d %d\n",rowls,cols);
      cont++;
    }else{
      fscanf(ptrFile,"%d,%d,%lf",&rowls,&cols,& value);
      if(value!=0.0){
        //Função de inserirCell <---AQUI
        printf("%d %d %.2f\n",rowls,cols,value );
      }

    }
   }
   fclose(ptrFile);
   return 0;
 }
