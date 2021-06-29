#include <stdio.h>

int linearSearch();

int n, q,c=0;
int s[1000000], t[100000000];

int main()
{
    int i, j, k = 0, a = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for (j = 0; j < q; j++)
    {
        scanf("%d", &t[j]);
    }

    k= linearSearch();

    printf("%d\n", k);

    return 0;
}

int linearSearch()
{
    int i, j,m=0;
    for (j = 0; j <= q - 1; j++)
    {
        for (i = 0; i <= n - 1; i++)
        {
            if (s[i] == t[j])
            {
                m++;
                break;
            }
        }
    }
    return m;
}
