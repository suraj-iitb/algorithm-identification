#include<stdio.h>

int main() {
    int n;
    int a[110];
    int j, flag, cnt, tmp;


    scanf("%d", &n);
    for(j = 0; j < n; j++) scanf("%d", &a[j]);

    flag = 1;
    cnt = 0;
    while(flag) {
        flag = 0;
        for(j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }

    for(j = 0; j < n; j++) printf("%d%c", a[j], ((j == n - 1) ? '\n' : ' '));
    printf("%d\n", cnt);

    return 0;
}
