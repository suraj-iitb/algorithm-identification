#include <stdio.h>

int search(int *S,int t, int n){
    int i;
    for (i = 0;i < n;i++)
        if (S[i] == t) return 1;
    return 0;
}

int main(){
    int n, q, S[10000], T[500], i, j, c = 0;
    scanf("%d", &n);
    for (i = 0;i < n;i++) scanf("%d", S + i);
    scanf("%d", &q);
    for (i = 0;i < q;i++) scanf("%d", T + i);
    for (i = 0;i < q;i++)
        c += search(S, T[i], n);
    
    printf("%d\n", c);
    return 0;
}
