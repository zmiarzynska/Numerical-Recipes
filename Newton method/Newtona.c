#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>

double complex funkcja(double complex z){
return z*z*z-1;
}

double complex pochodnaFunkcji(double complex z){
return 3*z*z;
}


int main(){
    FILE *plik;
     if((plik=fopen("newtona.dat","w"))==NULL) return -1;
   int N=400;
  
  double newtona(double complex z){
      int i=0,j=0,counter=0;
      double epsilon=1e-8;
       double roznicaX=0.0;
         double roznicaY=0.0;
          double complex pierwiastki[3]={1,-0.5+I*sqrt(3)/2.0,-0.5-I*sqrt(3)/2.0};
         double nrBasenu[3]={1,2,3}; 
        double temp=0;
    
  for(i=0;i<50;i++){
      z-=(funkcja(z)/pochodnaFunkcji(z));
      counter++;
      for(j=0;j<3;j++){
          roznicaX=creal(z)-creal(pierwiastki[j]);
          roznicaY=cimag(z)-cimag(pierwiastki[j]);
          
        
         if(fabs(roznicaX)<epsilon && fabs(roznicaY)<epsilon ) {
             temp =((double) counter);
             counter=0;
             return nrBasenu[j]+temp;
          }
      }
  }
  return 4;
  }
   
  double pixelX[N];
  double pixelY[N];
  double complex liczba=-2.0-I*2.0;
  double pixelZ[N][N];
  pixelY[0]=-2.0;  pixelX[0]=-2.0;  pixelZ[0][0]=newtona(liczba);
  double complex liczba2=0;
  int i =1,j=1;


  for(i=1;i<N;i++){
      pixelX[i]=pixelX[i-1]+4/399.;
      pixelY[i]=pixelY[i-1]+4/399.;
  }

  for(i=1;i<N;i++){
      for(j=1;j<N;j++){
       liczba2=pixelX[i]+I*pixelY[j];
        pixelZ[i][j]=newtona(liczba2);
               // printf("numer %d %d \n",i, j);
         fprintf(plik,"%.8f %.8f %.8f\n",pixelX[i],pixelY[j],pixelZ[i][j]);

      }

        
        
  }
fclose(plik);
    return 0;
}
