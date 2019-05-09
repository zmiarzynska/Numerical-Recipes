/////// metoda iteracji Seidela

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
  FILE *plik;
    if((plik=fopen("seidela.dat","w"))==NULL) return -1;
    clock_t start=clock();
    int N = 1000;
    double   n=1000;
    double   h=0.01;
    double  hh=0.0001;
    double   down[N+1];
             down[0]=0; down[N]=-1;
    double   diag[N+1];
             diag[0]=1;diag[N]=2; 
    double   up[N]; 
             up[0]=0; 
    double   b[N+1]; b[0]=1;
             b[N]=1;
int i=0,j=0;
double e=0.0000000001;
double blad=100,blad2;
for(i=1;i<=N-1;++i){
 
                  down[i]=-1;
                  diag[i]=2+hh;
                  up[i]=-1;
                  b[i]=0;
                  
                }


double xStare[N+1];
double xNowe[N+1];
int counter =0;
while(blad>e){


xNowe[0]=(b[0]-up[0]*xStare[1])/diag[0];
for(i=1;i<N;++i){

xNowe[i]=(b[i]-down[i]*xNowe[i-1]-up[i]*xStare[i+1])/diag[i];

}
xNowe[N]=(b[N]-down[i]*xNowe[N-1])/diag[N];


blad=fabs(b[0]-(diag[0]*xNowe[0]));
 xStare[0]=xNowe[0];
   for(i=1;i<N;++i){
       blad2=fabs(b[i]-(down[i]*xNowe[i-1]+diag[i]*xNowe[i]+up[i]*xNowe[i+1]));
       if (blad2>blad) blad=blad2;
        xStare[i]=xNowe[i];
   }

 blad2=fabs(b[N]-(down[N]*xNowe[N-1]+diag[N]*xNowe[N]));
 if(blad2>blad) blad=blad2;
 xStare[N]=xNowe[N];
 counter++;
//printf("Blad to: %.14f\n",blad);
//printf("Counter wynosi: %d\n",counter);
}


printf("Last Counter wynosi: %d\n",counter);


clock_t stop=clock();

stop-=start;
stop/=CLOCKS_PER_SEC/1000;

printf("Czas trwania programu: %d ms\n",stop);


for(i=0;i<=N;i++){
	fprintf(plik,"%d  %.14f\n",i,xNowe[i]);
}


fclose(plik);
return 0;
}