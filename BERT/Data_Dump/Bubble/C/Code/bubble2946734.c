#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])

int bubble_sort(int *a, const int N) {
    int flag = 1;
    int head = 0;
    int cnt = 0;
    // flag = 0 -> there is nothing to swap
    while(flag) {
        flag = 0;
        for(int i = N - 1; i > head; --i) {
            if(a[i] < a[i - 1]) {
            // swap
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                cnt++;
                flag = 1;
            }
        }
        // A[0 to head]: already sorted
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

