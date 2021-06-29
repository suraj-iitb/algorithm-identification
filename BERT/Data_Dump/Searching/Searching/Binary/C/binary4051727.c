#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define Q 50000

int main() {
    
    int n, q, i, j, array_n[N], array_q[Q], cnt=0, tmp[Q], k, flg, high, low, middle;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &array_n[i]);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf("%d", &array_q[i]);
    }
    
    for (i = 0; i < q; i++) {
        high = n - 1;
        low = 0;
        while (low <= high) {
            middle = (low + high) / 2;
            if (array_n[middle] == array_q[i]) {
                flg = 1;
                for (k = 0; k < cnt; k++) {
                    if (array_q[i] == tmp[k]) flg = 0;
                }
                if (flg) {
                    tmp[cnt] = array_q[i];
                    cnt++; 
                }
                break;
            } else if (array_n[middle] < array_q[i]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

