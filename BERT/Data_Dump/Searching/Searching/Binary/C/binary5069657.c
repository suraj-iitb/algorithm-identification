#include <stdio.h>
#include <stdlib.h>

void binary(int *, int, int);
int count = 0;

int main() {
    int i, j, n, *S, q, *T;
    
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
        binary(S, n, T[i]);
    }
    printf("%d\n", count);
    
    free(S);
    free(T);
    
    return 0;
}

void binary(int *s, int n, int t) {
    int left = 0, right = n, mid;
    while(left < right) {
        mid = (left + right)/2;
        if(s[mid] == t) {
            count++;
            break;
        } 
        else if(t < s[mid]) right = mid;
        else left = mid + 1;
    }
}


