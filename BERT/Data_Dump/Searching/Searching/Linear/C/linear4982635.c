#include <stdio.h>

    int n, q, a[100000], cnt = 0;
    int find(int t) {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == t)
            {
                return 1;
            }
        }
        return 0;
    }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        if (find(x) == 1)
        cnt++;
    }
printf("%d\n", cnt);
}
