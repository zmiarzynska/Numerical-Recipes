#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mnozenieWektor(double *tab, double *tab2,int size){
double sum=0;
for(int i=0;i<size;++i){
   sum+=tab[i]*tab2[i];
}
return sum; 
}

double liczenieNormy(double *tab,int size){
  double norma = 0;
  double temp=0;
  int i=0;
      for(i;i<size;++i){
         temp=tab[i]*tab[i];
         norma+=temp;
      }  
   norma=sqrt(norma);
   return norma;
}


int main(){


double A[3][3]={{4.0,-1.0,0.0},{-1.0,4.0,-1.0},{0.0,-1.0,4.0}};

double b[]={2.0,6.0,2.0};

int N = sizeof(b)/sizeof(double);
int i=0,j=0,k=0;
double norma;

double r[N],p[N],alfa,beta,x[N];
double x0[]={0.0,0.0,0.0};
double sum[N];
double mnoz[N];
double e=0.00000001;
for(int i=0;i<N;++i){        //r=b-Ax
for(j=0;j<N;++j){

   sum[i]+=A[i][j]*x0[j];

}
   r[i]=b[i]-sum[i];
   p[i]=r[i];
}
void mnozenieMacierz(){
for(i=0;i<N;++i){
   mnoz[i]=0;
      for(j=0;j<N;++j){
   
      mnoz[i]+=A[i][j]*p[j];
   
      }
   
   
   }

}


norma=liczenieNormy(r,N);
printf("Norma wynosi: %f\n",norma);
int counter=0;
while(e<norma){
counter++;
    mnozenieMacierz();

    alfa=mnozenieWektor(r,r,N)/mnozenieWektor(p,mnoz,N);
    double rkrk=mnozenieWektor(r,r,N);
    for(i=0;i<N;++i){
       x[i]+=alfa*p[i];
       r[i]-=alfa*mnoz[i];
      
    }

    norma=liczenieNormy(r,N);

    beta=mnozenieWektor(r,r,N)/rkrk;

    for(i=0;i<N;++i){
       p[i]=r[i]+beta*p[i];
    }

}
printf("%.16f\n",x[0]);

printf("%.16f\n",x[1]);

printf("%.16f\n",x[2]);
printf("%d\n",counter);

double odp[N]; 
i=0;j=0;
for(i;i<3;i++){
 
  for(j;j<3;j++){
      odp[i]+=A[i][j]*x[j];
      
      }
  j=0;
  odp[i]=b[i]-odp[i];
  printf("ODP %.16f\n",odp[i]);
}


return 0;

}