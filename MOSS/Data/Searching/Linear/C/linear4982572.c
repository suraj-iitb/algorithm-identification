#include <stdio.h>
int ans = 0, n, fn;
int main()
{
    scanf("%d", &n);
    int q[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    scanf("%d", &fn);
    int tgt[fn + 1];
    for (int i = 0; i < fn; i++)
    {
        scanf("%d", &tgt[i]);
    }
    for (int i = 0; i < fn; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tgt[i] == q[j])
            {
                ans = ans + 1;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
