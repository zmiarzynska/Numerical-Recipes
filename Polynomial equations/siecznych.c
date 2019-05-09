#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

double funkcja(double x){
    return -x*(x*(x-12)+46)+56; // -x^3+12x^2-46x+56   
}

double siecznej(double a,double b,double epsilon){
   int counter=0;
   sleep(1);
   double poczatek =a;
   double koniec=b;
   if(fabs(funkcja(a)-0.0)<epsilon) return a;
   if(fabs(funkcja(b)-0.0)<epsilon) return b;
   double zerowe=0;

   while(fabs(a-b)>epsilon){
        counter++;
       zerowe=(funkcja(a)*b-funkcja(b)*a)/(funkcja(a)-funkcja(b));
       if(fabs(funkcja(zerowe))<epsilon) {
           printf("Licznik iteracji dla przedzialu [%f,%f]: %d\n",poczatek,koniec,counter);
           return zerowe; 
           } 
       a=b;
       b=zerowe;
   }
    return -1;
}

int main(){
  clock_t start=clock();
  double e=0.00000001;
 // double e=0.0000000000000001;
  int k=0;
  double tabX1[]={2.0,3.5,5.0};
  double tabX2[]={3.0,4.5,6.0};
  double rozwiazania[]={0.0,0.0,0.0};
  for(k=0;k<3;++k){
      rozwiazania[k]=siecznej(tabX1[k],tabX2[k],e);
  }

  for(k=0;k<3;++k){
   printf("%d. miejsce zerowe to : %.8f\n",k+1,rozwiazania[k]);
  }
  clock_t stop=clock();
 stop-=start;
stop/=CLOCKS_PER_SEC/1000;

printf("Czas trwania programu: %ld ms\n",stop);

    return 0;
}