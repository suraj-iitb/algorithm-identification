#include <stdio.h>
void insertionSort(int A[1000], int N);
void Print(int Ar[1000], int M);

int main(void)
{
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    Print(array, n);
    insertionSort(array, n);
    return 0;
}

void Print(int Ar[1000], int M)
{
    for(int i = 0; i < M-1; i++)
    {
        printf("%d ", Ar[i]);
    }
    printf("%d", Ar[M-1]);
    printf("\n");
}

void insertionSort(int A[1000], int N)
{
    int v = 0;
    for(int j = 1; j < N; j++)
    {
        v = A[j];
        int k = j - 1;
        while(j >= 0 && A[k] > v)
        {
            A[k+1] = A[k];
            k--;
            A[k+1] = v;
        }
        Print(A, N);
    }
}
