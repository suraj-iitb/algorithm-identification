#include<stdio.h>

void order(int *,int);
void insertionSort(int *,int);

int main()
{
    int N,i,j;
    int A[100];

    scanf("%d",&N);
    for( i=0 ; i<N ; i++) scanf("%d",&A[i]);

    order(A,N);
    insertionSort(A,N);

    return 0;
}

void order(int A[], int N)
{
    int i;
    for( i=0; i<N; i++)
    {
        if( i>0 )printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertionSort(int A[],int N)
{
    int key,i,j;

    for( i=1; i<N; i++)
    {
        key = A[i];
        j = i-1;

        while( j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        order(A,N);
    }
}

