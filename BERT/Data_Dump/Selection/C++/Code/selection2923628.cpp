#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])

int selection_sort(int *a, const int N) {
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        int mini = i;
        for(int j = i + 1; j < N; ++j) {
            if(a[j] < a[mini]) mini = j;
        }
        if(i != mini) {
            int tmp = a[i];
            a[i] = a[mini];
            a[mini] = tmp;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    int cnt = selection_sort(a, n);
    arr_print_d0dn(a, n);
    printf("%d\n", cnt);
    return 0;
}

