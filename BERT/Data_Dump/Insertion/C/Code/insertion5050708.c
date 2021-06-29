#include <stdio.h>
#include <stdlib.h>

void insertionSort(int,int*);
#define M 1000
int A[M];

int main(){

        int N;
	scanf("%d",&N);

	//A = (int *)malloc(N * sizeof(int));
	
	for(int i=0;i<N;i++){
	    scanf("%d",&A[i]);
	}
	
       for(int i=0;i<N;i++){
           printf("%d",A[i]);
           if(i < N-1) printf(" ");
       }
       printf("\n");
       insertionSort(N,A);
	
	 
	return 0;
}


void insertionSort(int N,int *A){

   int i,v,j;

   
   for(i=1; i<N; i++){
      v=A[i];
      j=i-1;
      while(j>=0 && A[j] >v){
        
        A[j+1] = A[j];
        j--;
      }
      
      A[j+1] =v;
      
      for(int i=0;i<N;i++){
	printf("%d",A[i]);
	if(i < N-1) printf(" ");
      }
      printf("\n");
      
   }
   
}
