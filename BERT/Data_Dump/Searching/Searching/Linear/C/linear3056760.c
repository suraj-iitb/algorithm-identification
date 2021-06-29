#include <stdio.h>

int main(void)
{
    int i, j, n, q, t, C, S[10000];

    C = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", S + i);
    
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &t);
        for (j = 0; j < n; j++)
            if (S[j] == t) {
                C++;
                break;
            }
    }

    printf("%d\n", C);
    return 0;
}
