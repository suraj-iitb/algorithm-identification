#include <stdio.h>

int bsearch(int a[], int x, int n)
{
    int lb, ub;
    int m;

    lb = -1;
    ub = n;

    while (ub - lb > 1) {
        m = (ub + lb) / 2;
        if (a[m] >= x) ub = m;
        else lb = m;
    }

    return a[ub] == x;
}

int main() 
{
    int n, q;
    int s[1<<17];
    int i;
    int cnt, tmp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", s+i);
    scanf("%d", &q);
    cnt = 0;
    for (i = 0; i < q; i++) 
        if (bsearch(s, (scanf("%d", &tmp), tmp), n)) cnt++;
    printf("%d\n", cnt);

    return 0;
}

