#include <stdio.h>

static const int MAXNUMOFINPUT = 100;

int bubbleSort(int A[], int N);
int printArray(int A[], int N);

int main()
{
    int i;
    int N;
    int A[MAXNUMOFINPUT];
    int cnt = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    cnt = bubbleSort(A, N);
    printArray(A, N);
    printf("%d\n", cnt);

    return 0;
}

int bubbleSort(int A[], int N)
{
    int i = 0;
    int j;
    int flag = 1;
    int tmp;
    int cnt = 0;

    while (flag)
    {
        flag = 0;
        for (j = N - 1; j > i; j--)
        {
            if(A[j] < A[j - 1])
            {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                cnt++;
            }
        }

        i++;
    }

    return cnt;
}

int printArray(int A[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if (i < N - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

