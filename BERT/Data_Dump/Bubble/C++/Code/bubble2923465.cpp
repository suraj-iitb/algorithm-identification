#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])

int bubble_sort(int *a, const int N) {
    bool flag = true;
    int head = 0;
    int cnt = 0;
    while(flag) {
        flag = false;
        for(int i = N - 1; i > head; --i) {
            if(a[i] < a[i - 1]) {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                cnt++;
                flag = true;
            }
        }
        head++;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    int cnt = bubble_sort(a, n);
    arr_print_d0dn(a, n);
    printf("%d\n", cnt);
    return 0;
}

