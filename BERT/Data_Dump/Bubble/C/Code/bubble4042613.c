#include <stdio.h>
#define N 100

int main()
{
    int num, i, j, temp, count = 0;
    int A[N];

    scanf("%d", &num);
    for (i = 0; i < num; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < num - 1; i++)
    {
        for (j = num - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                count++;
            }
        }
    }

    for (i = 0; i < num; i++)
    {
        printf("%d", A[i]);
        if (i != num - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d\n", count);

    return 0;
}

