#include <stdio.h>

void print(int *, int, int);
void Bubble(int A[], int n)
{
    int pass, i, temp, swapped = 1, times = 0;
    for (pass = n - 1; pass >= 0 && swapped; pass--)
    {
        swapped = 0;
        for (i = 0; i < pass; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
                times += 1;
            }
        }
    }
    print(A, n, times);
}
int main()
{
    int N, A[100], i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    Bubble(A, N);
    return 0;
}
void print(int A[], int n, int times)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d\n", times);
}
