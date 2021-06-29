#include<stdio.h>

void bubbleSort(int *A, int N)
{
    int flag = 1;
    int buff, count = 0;
    while(flag == 1){
        flag = 0;
        for(int j = N-1; j > 0; j--)
        {
            if(A[j] < A[j-1])
            {
                count++;
                buff = A[j];
                A[j] = A[j-1];
                A[j-1] = buff;
                flag = 1;
            }
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
    bubbleSort(A, N);
    return 0;
}

