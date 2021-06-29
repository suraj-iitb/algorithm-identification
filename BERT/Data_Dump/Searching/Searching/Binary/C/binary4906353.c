#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int n, q;
    scanf("%d", &n);

    int S[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    int tmp, ans = 0;
    int l, r, mid;

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &tmp);

        l = 0;
        r = n;

        while (l < r)
        {
            mid = (l + r) / 2;
            if (tmp > S[mid])
            {
                l = mid + 1;
            }
            else if (tmp < S[mid])
            {
                r = mid;
            }
            else
            {
                ans++;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
