#include <stdio.h>

int main(void)
{
    int n, q;
    scanf("%d", &n);
    int *S = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    int num = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &S[n]);
        int i = 0;
        while (S[i] != S[n])
        {
            i++;
        }
        if (i != n)
        {
            num++;
        }
    }
    printf("%d\n", num);
    return 0;
}
