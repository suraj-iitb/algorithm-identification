#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 100

void Print(int A[MAX], int N)
{
    for(int i = 0;i < N;i++) {
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

int selectionSort(int *A,int N)
{
    int counter = 0;
    for(int i = 0;i < N-1;i++) {
        int minj = i;
        for(int j = i;j < N;j++)
            if(A[j] < A[minj])
                minj = j;
        if(i != minj) {
            swap(A[i],A[minj]);
            counter++;
        }
    }
    return counter;
}

int main()
{
    int N;
    int A[MAX];

    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&A[i]);

    int num = selectionSort(A,N);
    Print(A,N);
    printf("%d\n",num);
}

