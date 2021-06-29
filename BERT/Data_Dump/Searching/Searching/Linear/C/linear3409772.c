#include <stdio.h>
#include <stdlib.h>

int linearsearch(long T, long S[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(S[i] == T) return 1;
    }
    return 0;
}

int main(){
    int n, q, ans = 0;
    scanf("%d", &n);
    long S[n];
    int i;
    for(i = 0; i < n; i++){
        scanf("%ld", &S[i]);
    }
    scanf("%d", &q);
    long T[q];
    for(i = 0; i < q; i++){
        scanf("%ld", &T[i]);
    }
    for(i = 0; i < q; i++){
        ans += linearsearch(T[i], S, n);
    }
    printf("%d\n", ans);
    return 0;
}
