#include <stdio.h>
int linear(int[], int, int);
int main()
{
    int i, j, s[10001], t, n, q, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    scanf("%d", &q);
    for (j = 0; j < q; j++)
    {
        scanf("%d", &t);
        if (linear(s, n, t))
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
int linear(int s[], int n, int t)
{
    int i = 0;
    s[n] = t;
    while (s[i] != t)
        i++;
    return i != n;
}
