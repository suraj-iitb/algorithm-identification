#include <stdio.h>

#define N 100

int main(){
    int n, i, j, flg, num[N], tmp, cnt = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    flg = 1;
    while (flg) {
        flg = 0;
        for (j = n - 1; j >= 1; j--) {
            if (num[j] < num[j-1]) {
                tmp = num[j];
                num[j] = num[j-1];
                num[j-1] = tmp;
                flg = 1;
                cnt++;
            }
        }
    }
    
    for (i = 0; i < n - 1; i++) {
        printf("%d ", num[i]);
    }
    printf("%d\n%d\n", num[i], cnt);
    return 0;
}

