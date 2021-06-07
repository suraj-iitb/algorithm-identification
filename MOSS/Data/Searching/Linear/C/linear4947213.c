#include <stdio.h>
#include <stdlib.h>

#define MAX_n 10000
#define MAX_q 500
#define NOT_FOUND 10001
int n=MAX_n;
int q=MAX_q;

int linearSearch(int key, int *A);

int main(void)
{
    int count = 0;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    int T[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < q; i++)
    {
        count += linearSearch(T[i], S);
    }
    printf("%d\n", count);
    return 0;
}

int linearSearch(int key,int *A)
{
    int i = 0;
    A[n] = key;
    while(A[i] != key)
    {
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    return 1;
}
