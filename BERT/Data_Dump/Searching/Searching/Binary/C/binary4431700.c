#include <stdio.h>
#include <stdlib.h>

int bi_search(int S[], int s, int e, int T);

int bi_search(int S[], int s, int e, int T)
{
    int idx;

    //printf("%d : %d -> %d ( [%d] )\n", s, e, S[(s+e)/2], (s+e)/2);

    if(s > e) {
        return 0;
    }

#if 0
    0 1 2 3 4 5 6 7
    0 1 2
            4 5 6 7

    0 1 2 3 4 5 6
    0 1 2
    0
        2

            4 5 6
#endif

    idx = (s + e) / 2;
    if(S[idx] == T) {
        return 1;
    } else if(S[idx] > T) {
        return bi_search(S, s, (s+e)/2-1, T);
    } else {
        return bi_search(S, (s+e)/2+1, e, T);
    }
}

int main()
{
    int n;
    int *S;
    int q;
    int T;
    int C;
    int i;

    scanf("%d", &n);
    S = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    C = 0;
    for(i = 0; i < q; i++) {
        scanf("%d", &T);
        //printf("%d\n", T);
        if(bi_search(S, 0, n-1, T) == 1) {
            //printf("found\n");
            C += 1;
        }
    }
    printf("%d\n", C);
    return 0;
}
