#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <stdlib.h>
#include <math.h>


double mnozenieSkalarne(double *tab, double *tab2,int size){
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
double a[] = { 1,2,3,2,4,5,3,5,-1};
int i=0,j=0,n=0;
gsl_matrix *Q =gsl_matrix_alloc(3,3);
gsl_matrix *R =gsl_matrix_alloc(3,3); 
gsl_matrix_view m  = gsl_matrix_view_array (a, 3, 3);
int N = 3;
double lambdaN[]={0,0,0};
double lambdaN_1[]={0,0,0};
double czyWszystkie=0;
double epsilon=0.00000001;
void qrDecomp(){
 

gsl_vector *tau = gsl_vector_alloc (3);

gsl_linalg_QR_decomp(&m.matrix, tau);

gsl_linalg_QR_unpack(&m.matrix,tau,Q,R);


  
  

}

while(1){
qrDecomp();

//RQ
gsl_blas_dgemm(CblasNoTrans,CblasNoTrans,1.0,R,Q,0.0,&m.matrix);

	for(n=0;n<3;++n){
         lambdaN_1[n]=lambdaN[n];
        for(j=0;j<3;++j){
        	if(n==j)lambdaN[j]=gsl_matrix_get(&m.matrix,n,j);
        }

	}


   czyWszystkie=0;
   for(n=0;n<3;++n){
      
          if(fabs(lambdaN_1[n]-lambdaN[n])<epsilon) czyWszystkie++; 
   }
   if(czyWszystkie==3) break;
}

 printf(" Wartosci wlasne \n");
 for(i=0;i<3;++i){
 	printf(" %f \n",lambdaN[i]);

 }


	return 0;
}