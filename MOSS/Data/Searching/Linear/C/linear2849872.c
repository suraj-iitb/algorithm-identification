
#include <stdio.h>

int main(void)
{
    int i, j, cnt, n1, n2, sum = 0;
    int A[1000000], B[1000000];

    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &n2);
    for (j = 0; j < n2; j++)
    {
        scanf("%d", &B[j]);
    }

    for (j = 0; j < n2; j++)
    {
        cnt = 0;
        for (i = 0; i < n1; i++)
        {
            if (A[i] == B[j] && cnt == 0)
            {
                sum += 1;
                cnt += 1;
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
