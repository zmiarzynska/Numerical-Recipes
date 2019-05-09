#include <stdlib.h>
#include <stdio.h>




int main(){

FILE *plik;
    if((plik=fopen("sherman.dat","w"))==NULL) return -1;
   int N = 1000;
double   n=1000;
    double   h=0.0001;
    double   dzielnik=0;
    double   dzielnik2=0;
    double   down[N+1];
             down[0]=0; down[N]=1;
    double   diag[N+1];
             diag[0]=1;diag[N]=-2; 
    double   up[N]; 
             up[0]=0; 
    double   b[N+1]; b[0]=1;
             b[N]=0;
    double   z[N+1];   
     double  q[N+1];    
     double  u[N+1]; u[0]=0;
            u[N]=1;
    double  v[N+1]; v[0]=1;
             v[N]=0;
             for(int i=1;i<=N-1;++i){
 
                  down[i]=1;
                  diag[i]=-2+h;
                  up[i]=1;
                  b[i]=0;
                  u[i]=0;
                  v[i]=0;
                }
    
              
    
     
    
    double lambda[N],beta[N+1];
    double lambda2[N],beta2[N+1];


   
    lambda[0]=up[0]/diag[0];
    beta[0]=b[0]/diag[0];

    lambda2[0]=up[0]/diag[0];
    beta2[0]=u[0]/diag[0];

    for(int i=1;i<=N-1;++i){
 
      dzielnik=diag[i]-(down[i]*lambda[i-1]);
      lambda[i]=(up[i])/dzielnik;

      beta[i]=(b[i]-down[i]*beta[i-1])/dzielnik;


     dzielnik2=diag[i]-(down[i]*lambda2[i-1]);
     lambda2[i]=(up[i])/dzielnik2;

      beta2[i]=(u[i]-down[i]*beta2[i-1])/dzielnik2;


 

    }

       dzielnik=diag[N]-(down[N]*lambda[N-1]);
       beta[N]=(b[N]-down[N]*beta[N-1])/dzielnik;
    
       z[N]=beta[N];
        
       dzielnik2=diag[N]-(down[N]*lambda2[N-1]);
       beta2[N]=(u[N]-down[N]*beta2[N-1])/dzielnik2;
    
       q[N]=beta2[N];
   
   //  printf("%f\n",beta2[N]);

    for(int i=N-1;i>=0;--i){

        z[i]=beta[i]-(lambda[i]*z[i+1]);

        q[i]=beta2[i]-(lambda2[i]*q[i+1]);
       
  //   printf("%f\n",z[i]);
  //   printf("%f\n",q[i]);
        
    }   
    double w[N+1];

    double vTz=0;
    double vTq=0;
    

    for(int i=0;i<=N;++i){

        vTz+=v[i]*z[i];
        vTq+=v[i]*q[i];


    }

double odp[N+1];
int j=0;
    for(int i=0;i<=N;i++){

       
        w[i]=z[i]-(((vTz)/(1+vTq))*q[i]);
 //printf("%.14f\n",w[i]);
 fprintf(plik,"%d %.14f\n",i,w[i]);
     
   
    }

fclose(plik);

 for(int i=0;i<=N;i++){

       
       odp[i]=down[i]*w[j]+diag[i]*w[j+1]+up[i]*w[j+2];
       printf("%.16f\n",odp[i]);
       j++;
 }

    return 0;
}