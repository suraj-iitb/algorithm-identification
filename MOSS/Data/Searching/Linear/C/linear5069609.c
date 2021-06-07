#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, *S, q, *T, count = 0;
    
    /* 入力 */
    scanf("%d", &n);
    S = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    T = (int *)malloc(q * sizeof(int));
    for(i = 0; i < q; i++) {
        scanf("%d", &T[i]);
        
        /* リニアサーチ */
        for(j = 0; j < n; j++) {
            if(T[i] == S[j]) {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    
    free(S);
    free(T);
    
    return 0;
}

