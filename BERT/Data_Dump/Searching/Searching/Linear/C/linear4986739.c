#include <stdio.h>
int main()
{
    int x, k, t;
    int q = 0;
    scanf("%d", &x);
    int a[10000];
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &k);
        for (int i = 0; i < x; i++)
        {
            if (k == a[i])
            {
                q++;
                break;
            }
        }

    }
        printf("%d\n", q);
        return 0;
}
