#include <stdio.h>
#define MAX 100000
int main()
{
    int n;
    int A[MAX], x;
    int i, j, k, count = 0;

    scanf("%d", &n);

    //Initialise zeros for all the indices
    for (i = 0; i < MAX; i++)
    {
        A[i] = 0;
    }

    //Output array to
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        A[x] = A[x] + 1;
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < A[i]; j++)
        {
            printf("%d", i);
            if (count < n - 1)
            {
                printf(" ");
                count++;
            }
        }
    }
    printf("\n");

    return 0;
}
