#include <stdio.h>

int search(int A[], int N, int key)
{
    int i = 0;
    A[N] = key;

    while (A[i] != key)
        i++;
    return (i != N);
}

int main(void)
{
    int N, Q, i, key;
    int S[10000 + 1];
    int count = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &S[i]);

    scanf("%d", &Q);
    for (i = 0; i < Q; i++)
    {
        scanf("%d", &key);
        if (search(S, N, key))
            count++;
    }
    printf("%d\n", count);

    return 0;
}
