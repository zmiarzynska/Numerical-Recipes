#define N 100

#include <stdio.h>
#include <stdlib.h>



int main(){
    FILE *plik;
    if((plik=fopen("thomas.dat","w"))==NULL) return -1;
    double   n=N;
    double   h=1/n;
    double   dzielnik=0;
    double   a[N+1];
             a[0]=0; a[N]=0;
    double   b[N+1];
             b[0]=1;b[N]=1; 
    double   c[N]; c[0]=0; 
    double   f[N+1]; f[0]=0;
             f[N]=1;
    double   y[N+1];      
             for(int i=1;i<=N-1;++i){
 
                  a[i]=1/(h*h);
                  b[i]=-2/(h*h);
                  c[i]=1/(h*h);
                  f[i]=0;
                }
    
              
    
     
    
    double lambda[N],beta[N+1];


   
    lambda[0]=c[0]/b[0];
    beta[0]=f[0]/b[0];
  //   printf("B[%d]=%.3f,Y[%d]=%.3f\n",0,lambda[0],0,beta[0]);
    for(int i=1;i<=N-1;++i){
 
      dzielnik=b[i]-(a[i]*lambda[i-1]);
      lambda[i]=(c[i])/dzielnik;

      beta[i]=(f[i]-a[i]*beta[i-1])/dzielnik;
  //   printf("B[%d]=%.3f,Y[%d]=%.3f\n",i,lambda[i],i,beta[i]);

    }

       dzielnik=b[N]-(a[N]*lambda[N-1]);
       beta[N]=(f[N]-a[N]*beta[N-1])/dzielnik;
    
 y[N]=beta[N];
   
     printf("%f\n",beta[N]);
         fprintf(plik,"#n*h y[n] \n");
        fprintf(plik, "%f %f\n",n*h,y[N]);	


    for(int i=N-1;i>=0;--i){

        y[i]=beta[i]-(lambda[i]*y[i+1]);
       
     printf("%f\n",y[i]);
        fprintf(plik,"%f %f\n",i*h,y[i]);
    }
        
   fclose(plik);

    return 0;
}