#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 100

void Print(int A[MAX], int N)
{
    for(int i = 0;i < N;i++) {
        if(i == N-1)
            printf("%d",A[i]);
        else
            printf("%d ", A[i]);
    }
    printf("\n");
}

int bubble(int *A,int N)
{
    int counter = 0;
    int flag = 1;
    while(flag) {
        flag = 0;
        for(int j = N-1;j > 0;j--) {
            if(A[j] < A[j-1]) {
                swap(A[j],A[j-1]);
                flag = 1;
                counter++;
            }
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

    int num = bubble(A,N);
    Print(A,N);
    printf("%d\n",num);

    return 0;
}

