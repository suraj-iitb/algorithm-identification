#include<stdio.h>
#define MAX 1024
void insertionSort(int *A,int N);
int main(void){
    int A[MAX];
    int N;
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(i=0;i<N-1;i++)
        printf("%d ",A[i]);
    printf("%d",A[N-1]);
    printf("\n");
    insertionSort(A,N);
    return 0;
}
void insertionSort(int *A,int N){
    int i,j,k;
    int v;
    for(i=1;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    for(k=0;k<N-1;k++)
        printf("%d ",A[k]);
    printf("%d",A[N-1]);
    printf("\n");
    }
}
