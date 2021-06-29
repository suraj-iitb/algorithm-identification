#include <stdio.h>

int main(void)
{
    int i, j, cnt, n1, n2, sum = 0, pivot;
    //int A[100000000], B[100000000];

    scanf("%d", &n1);
    int A[n1];
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &n2);
    int B[n2];
    for (j = 0; j < n2; j++)
    {
        scanf("%d", &B[j]);
    }

    pivot = A[n1 / 2];

    for (j = 0; j < n2; j++)
    {
        if (B[j] < pivot)
        {
            //cnt = 0;
            for (i = 0; i < n1 / 2; i++)
            {
                if (A[i] == B[j])
                {
                    sum += 1;
                    //cnt += 1;
                    break;
                }
            }
        }
        else
        {
            for (i = n1 / 2; i < n1; i++)
            {
                if (A[i] == B[j])
                {
                    sum += 1;
                    //cnt += 1;
                    break;
                }
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
