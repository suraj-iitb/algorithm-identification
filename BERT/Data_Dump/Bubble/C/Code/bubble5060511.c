#include <stdio.h>
#include <stdlib.h>

int* BubbleSort(int,int*);
//#define M 1000
//int A[M];

int main(){

      int N,*A;
      scanf("%d",&N);

      A = (int *)malloc(N * sizeof(int));
	
      for(int i=0;i<N;i++){
	    scanf("%d",&A[i]);
	
      }
      
      A=BubbleSort(N,A);
       
      return 0;
}

int* BubbleSort(int N,int* A){

	int flag=1,s=0,cout=0;
	
	while(flag==1){
	  
	   flag =0;
	   for(int j=N-1;0<j;j--){
	      if(A[j-1]>A[j]){
	         s=A[j];
	         A[j] = A[j-1];
	         A[j-1]=s;
	         flag =1;
	         cout++;
	      }
	  }

	}
	
        for(int i=0;i<N;i++){
           printf("%d",A[i]);
           if(i < N-1) printf(" ");
        }
       
        printf("\n");	
	printf("%d\n",cout);
	return A;
}
