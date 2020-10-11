#include <stdio.h>
#define M 1000

void insertionSort(int[],int);

int main(void){
    int n,i;
    int A[M+1];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    insertionSort(A,n);
    
}
void insertionSort(int A[],int N){
    int v,i,j;
    for(i=0;i<N;i++){
        v = A[i];
        j = i-1;
        while( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
	for(j=0;j<N-1;j++)printf("%d ",A[j]);
	printf("%d\n",A[j]);
    }
}

