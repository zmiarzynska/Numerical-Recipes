#include <stdio.h>
#include <stdlib.h>


int main(){
FILE *plik;
     if((plik=fopen("logistic.dat","w"))==NULL) return -1;
   double k=2;
   int n=0;
   double x;
   
   double function(double x){
      return k*x*(1-x);
    }
    while(k<=4){
        n=0;
        while(n<150){
            x=function(x);
    fprintf(plik,"%.8f %.8f \n",k,x);
            n++;
        }
      k+=0.003;
    }
fclose(plik);
    return 0;
}







