#include<stdio.h>

void insertionSort(int *A, int N)
{
    int v, j;
    for(int i = 0; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(int k = 0; k < N; k++){
            printf("%d", A[k]);
            if(k != N-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void){
    int N, a;
    
    scanf("%d",&N);
    int A[N];
    
    for(int i = 0; i < N;i++)
    {
        scanf("%d",&a);
        A[i] = a;
    }
    insertionSort(A, N);
    return 0;
}

