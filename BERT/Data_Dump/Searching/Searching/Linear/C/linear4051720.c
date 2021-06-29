#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define Q 500

int main() {
    
    int n, q, i, j, array_n[N], array_q[Q], cnt=0, tmp[Q], k, flg;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &array_n[i]);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf("%d", &array_q[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            if (array_n[i] == array_q[j]) {
                flg = 1;
                for (k = 0; k < cnt; k++) {
                    if (array_q[j] == tmp[k]) flg = 0;
                }
                if (flg) {
                    tmp[cnt] = array_q[j];
                    cnt++; 
                }
            }
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

