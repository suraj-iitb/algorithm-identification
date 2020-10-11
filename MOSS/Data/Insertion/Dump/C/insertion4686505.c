#include <stdio.h>

static void print_array(int array[], int array_len)
{
    for (int i = 0; i < array_len; i++)
    {
        printf("%d", array[i]);
        if (i != array_len - 1)
            printf(" ");
    }
    printf("\n");
}

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    /* 出力 */
    print_array(A, N);

    /* 挿入ソート */
    for (int i = 1; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        print_array(A, N);
    }
    return 0;
}
