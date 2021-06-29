#include<stdio.h>
#define MAX 1000

void Print(int A[MAX],int N)
{
    for(int i = 0;i < N;i++) {
        if(i == N-1)
            printf("%d",A[i]);
        else
            printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionSort(int *A,int N)
{
    for(int i = 1;i < N;i++) {
        int v = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        Print(A,N);
    }
}


int main()
{
    int A[MAX];
    int n;

    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%d",&A[i]);
    }
    Print(A,n);
    insertionSort(A,n);
    return 0;
}

