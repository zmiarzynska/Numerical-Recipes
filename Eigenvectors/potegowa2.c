#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

double skalarne(double *tab, double *tab2,int size){
double sum=0;
for(int i=0;i<size;++i){
   sum+=tab[i]*tab2[i];
}
return sum; 
}

int main(){
 int counter=0;
 double A[3][3]={{1.0,2.0,3.0},{2.0,4.0,5.0},{3.0,5.0,-1.0}};
 int N = sizeof(A[1])/sizeof(double);
 int i=0,j=0,k=0;
 double epsilon=0.00000001;
 double w[3]={1.0,1.0,1.0};
 double v[3]={1.0,1.0,1.0};
 double u[3]={1.0,1.0,1.0};
 double lambdaN[]={0.0,0.0,0.0};
 double lambdaN_1[]={0.0,0.0,0.0};
 double suma[3]={0.0,0.0,0.0};
 double tablicaV[3][3]={{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0}};
printf("n wynosi %d\n",N);



for(k=0;k<N;k++){
    do{
         for(i=0;i<N;++i){
             w[i]=0;
             for(j=0;j<N;++j){
            
                w[i]+=A[i][j]*tablicaV[k][j]; 
               // printf("%d wektor, W[%d] wynosi %f\n",k,i,w[i]);
             }
            
         }   
     
     lambdaN_1[k]=lambdaN[k];
     for(i=0;i<N;++i){
         u[i]=w[i]/liczenieNormy(w,N);
     }


      lambdaN[k]=liczenieNormy(w,N)/liczenieNormy(tablicaV[k],N);
   
    for(i=0;i<k;++i){
        
        for(j=0;j<N;++j){
            
            suma[j]+=skalarne(tablicaV[i],u,N)*tablicaV[i][j];
        }
    }

    for(i=0;i<N;++i){
     
        tablicaV[k][i]=u[i]-suma[i];
      
        suma[i]=0;
    }
        
           
        counter++;
     }while(fabs(lambdaN_1[k]-lambdaN[k])>epsilon);        
 }


 for(i=0;i<3;i++){
	printf("lambda %.10f\n",lambdaN[i]);

}
  printf("Counter %d\n",counter);

    return 0;
}