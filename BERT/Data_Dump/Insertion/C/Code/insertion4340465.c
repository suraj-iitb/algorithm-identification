#include<stdio.h>

void insertionSort(int*, int);

int main(){
    int N, i= 0;
    
    scanf("%d", &N);
    //printf("%d", N);
    
    int A[N];
    
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    insertionSort(A, N);
    
    return 0;
}

void insertionSort(int* A, int N){
	int i = 0, j = 0, k = 0, temp = 0;
	
	for(i = 0 ;i <= N - 1; i++){
        temp = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > temp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
        for(k = 0; k < N; k++){
            if(k == N - 1){
            	printf("%d", A[k]);
            }else{
            	printf("%d ", A[k]);
            }
        }
        printf("\n");
    }	
}

