#include <stdio.h>
 
void printNumbers(int A[], int N){
    int i;
    for( i=0; i<N; i++){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}
 
void swap(int *a, int *b){
    int temp;
    temp = *a;
     
    *a =*b;
    *b = temp;
}
 
 
int selectionSort(int A[],int N){
    int i;
    int j;
    int minj;
    int count=0;
     
    for(i=0; i<N; i++){
        minj=i;
        for(j=i; j<N; j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj != i){
            swap(&(A[i]),&(A[minj]));
            count++;
        }
    }
    return count;
}
 
 
int main() {
    int N;
    int i;
    int count;
    int A[100];
    scanf("%d",&N);
     
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
     
    count = selectionSort(A, N);
    printNumbers(A,N);
    printf("%d\n",count);
     
    return 0;
}
