#include<stdio.h>
void insertionSort(int A[], int N);
void printArray(int A[], int N);
int main(void){
    int A[100];
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    insertionSort(A, N);
}


void insertionSort(int A[], int N){
    int i,j,v;
    for(i=1;i<N;i++){
        printArray(A, N);
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    printArray(A, N);
}


void printArray(int A[], int N){
    int k = 0;
    while(k < N){
        printf("%d",A[k]);
        if(k < N-1){
            printf(" ");
        }else{
            printf("\n");
        }
        k++;
    }
}
