#include <cstdio>

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int bubbleSort(int A[], int N)
{
    int flag = 1;
    int cnt = 0;
    while (flag)
    {
        flag = 0;
        for (int j = N-1; j > 0; j--)
        {
            if (A[j] < A[j-1])
            {   
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N;
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int cnt = bubbleSort(A, N);
    trace(A, N);
    printf("%d", cnt);
    printf("\n");

    return 0;
}
