#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int n, q;
    int i, j;
    int *S, *T;
    S = (int*)malloc(sizeof(int) *10000);
    T = (int*)malloc(sizeof(int) *500);
    int cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }

    for (i = 0; i < q; i++){
        for (j = 0; j < n; j++){
            if (T[i] == S[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
