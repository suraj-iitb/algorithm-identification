#include<stdio.h>

void selectionSort(int *A, int N)
{
    int minj, buff;
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        minj = i;
        for(int j = i; j < N; j++)
        {
            if(A[j] < A[minj])
            {
                minj = j;
            }
        }
        if(i != minj){
            buff = A[i];
            A[i] = A[minj];
            A[minj] = buff;
            count++;
        }
        
    }
    for(int k = 0; k < N; k++){
        printf("%d", A[k]);
        if(k != N-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",count);
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
    selectionSort(A, N);
    return 0;
}

