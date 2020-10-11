#include <stdio.h>

#define N 100

int main(){
    int n, i, j, num[N], tmp, cnt = 0, min, flg;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    for (i = 0; i < n; i++) {
        flg = 0;
        min = i;
        for (j = i; j < n; j++) {
            if (num[j] < num[min]) {
                min = j;
                flg = 1;
            }
        }
        tmp = num[i];
        num[i] = num[min];
        num[min] = tmp;
        if (flg) cnt++;
    }
    
    for (i = 0; i < n - 1; i++) {
        printf("%d ", num[i]);
    }
    printf("%d\n%d\n", num[i], cnt);
    return 0;
}

