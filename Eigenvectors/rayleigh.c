#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
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
	double copyA[9]={0,0,0,0,0,0,0,0,0};
	double A[3][3] = { {1,2,3},{2,4,5},{3,5,-1}};
	double vK[]={1,0,0};
	double lambdaN[]={8.0,-4.0,0.0};
	double lambdaN_1[]={0,0,0};
	double I[]={1,0,0,0,1,0,0,0,1}; // jako wektor a to macierz 3x3
	double w[]={0,0,0}; // niewiadoma
	double mnoz[3]={0,0,0};
	int i=0,j=0,k=3,n=0;
	int N = sizeof(A[0])/sizeof(double);
	double epsilon=0.00000001;
   
    void  mnozenieMacierzWektor(){
		for(i=0;i<N;++i){
  		 mnoz[i]=0;
     	for(j=0;j<N;++j){
   
  		    mnoz[i]+=A[i][j]*vK[j];
   
      		}	
   
   
   		}	
   	
	}

	void lu(){

  gsl_matrix_view m  = gsl_matrix_view_array (copyA, 3, 3);
  gsl_vector_view v  = gsl_vector_view_array (vK, 3);
  gsl_vector *x = gsl_vector_alloc (3);
  int s;
  gsl_permutation * p = gsl_permutation_alloc (3);
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
  gsl_linalg_LU_solve (&m.matrix, p, &v.vector, x);
  //printf ("x = \n");
  //gsl_vector_fprintf (stdout, x, "%g");

  for(i=0;i<3;++i){
     w[i]=gsl_vector_get(x,i);
    }

  gsl_permutation_free (p);
  gsl_vector_free (x);

	}

	void A_lambdaI(){
         for(i=0;i<(3*N);++i){
           copyA[i]=a[i]-lambdaN[k]*I[i];
         }        
        
	}


    // wlasciwy kod
    for(k=0;k<N;++k){
            vK[0]=1;
            vK[1]=0;
            vK[2]=0;
  		do{
  			 A_lambdaI();

 			   lu();
   			 //solve (A - lambda *I)w= v; dla w 


   			 for(i=0;i<N;++i){
    			vK[i]=w[i]/(liczenieNormy(w,N));
   			 }
 
            lambdaN_1[k]=lambdaN[k];
            

            mnozenieMacierzWektor();
          
			lambdaN[k]=mnozenieSkalarne(vK,mnoz,N);
 			    printf("lambda ehemehe %.16f\n",lambdaN[k]);
   
  		} while(fabs(lambdaN_1[k]-lambdaN[k])>epsilon);  	

        printf("lambda  %d %f\n",k,lambdaN[k]);
 	}



 	


	return 0;
}