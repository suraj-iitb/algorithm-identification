#include <stdio.h>

void trace(int A[], int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d",A[i]);
		if (i==N-1){
			printf("\n");
		}
		else{
			printf(" ");
		}
	}
} 

void insertionSort(int A[], int N){
	int i,j,key;
	for (i=1;i<N;i++){
		key = A[i];
		j=i-1;
		while (j >= 0 && A[j] > key){
			A[j+1] = A[j];
            j--;     
		}
        A[j+1] = key; 
		trace(A,N);	
	}
    
    
   
}

int main(){
	int N,i;
	int A[100];
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	trace(A,N);
	insertionSort(A,N);
}


