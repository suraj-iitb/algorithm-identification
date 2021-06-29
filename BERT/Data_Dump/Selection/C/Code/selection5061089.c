#include <stdio.h>
#include <stdlib.h>

int* SelectionSort(int,int*);

int main(){

      int N,*A;
      scanf("%d",&N);

      A = (int *)malloc(N * sizeof(int));
	
      for(int i=0;i<N;i++){
	    scanf("%d",&A[i]);
	
      }
      
      A=SelectionSort(N,A);
       
      return 0;
}

int* SelectionSort(int N,int* A){

	int minj,s=0,cout=0,j=0;
	  
       for(int i=0;i<N;i++){
           minj =i;
	   for(j=i;j<N;j++){
	      if(A[minj]>A[j]) minj=j;
	     
	   } 
	   
	   s=A[i];
	   A[i] = A[minj];
	   A[minj]=s;  
	   if(i != minj )cout++;
	}
	
        for(int i=0;i<N;i++){
           printf("%d",A[i]);
           if(i < N-1) printf(" ");
        }
       
        printf("\n");	
	printf("%d\n",cout);
	return A;

}
