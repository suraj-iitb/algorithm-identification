//2020 2.16 挿入ソート

#include <stdio.h>
#define MAX 100 

void insertionSort(int *,int);
void Print(int *,int);

int main()
{
    int a;
    int i;
    int A[MAX];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }
    Print(A,a);
    insertionSort(A,a);

    return 0;
}

void insertionSort(int *A,int N)
{
    int i,j;
    int temp;

    for(i=1;i<N;i++)
    {
        temp=A[i];  //比較値temp
        j = i;
        while(j>0 && A[j-1]>temp)
        {
            A[j] = A[j-1];
            A[j-1] = temp;
            j--;
        }
        Print(A,N);
    }
    return;
}

void Print(int *A,int N)
{
    for(int i=0;i<N;i++)
    {
        if(i==0) printf("%d",A[i]);
        else printf(" %d",A[i]);
    }
    printf("\n");
    return;
}
