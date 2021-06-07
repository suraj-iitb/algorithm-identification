#include <stdio.h>

int main(){

    int n, q, i, j;
    int cnt = 0;
    int once = 0;

    scanf("%d", &n);
    int S[n];
    for(i = 0; i< n; i++) scanf("%d", &S[i]);

    scanf("%d", &q);
    int T[q];
    for(i = 0; i< q; i++) scanf("%d", &T[i]);

    for(i = 0; i < q; i++){
        for(j = 0; j < n; j++){
            if(once == 0 && T[i] == S[j]){
                cnt++;
                break;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
