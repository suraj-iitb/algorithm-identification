#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int i, j, a, n, q, count = 0;
    int s[10001], t[501];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    scanf("%d", &q);
    for(i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }


    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
        if(s[i] == t[j]) {
            count++;
            t[j] = -1;
            break;
        }
        }
    }

    printf("%d\n", count);

    return 0;
}
