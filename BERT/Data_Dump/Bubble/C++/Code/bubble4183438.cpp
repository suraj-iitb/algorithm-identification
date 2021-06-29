#include <stdio.h>

int BubbleSort(int A[], int N)
{
    int cnt = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j > 0; j--)
        {
            if (A[j - 1] > A[j])
            {
                int val = A[j - 1];
                A[j - 1] = A[j];
                A[j] = val;
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int rel = BubbleSort(A, N);
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d", rel);
    printf("\n");
    return 0;
}
