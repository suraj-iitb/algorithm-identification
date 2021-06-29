#include <stdio.h>

int linearsearch(int *A, int key, int n) 
{
    int i = 0;
    A[n] = key;

    while(A[i] != key)
    i++;
    if (i==n) return 0;
    else
    return 1;
}

int main(void)
{
    int n, q, i;
    int S[10000];
    int T[10000];
    int count = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(i = 0; i < q; i++) scanf("%d", &T[i]);

    for(i = 0; i < q; i++)
    count = count + linearsearch(S, T[i], n);
    printf("%d\n", count);

    return 0;
}
