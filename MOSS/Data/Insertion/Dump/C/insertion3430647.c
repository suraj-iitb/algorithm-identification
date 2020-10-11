#include <stdio.h>

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp

void print_list(int a[], int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n - 1)
            printf("\n");
        else
            printf(" ");
    }
}

int main(int argc, char **argv) {
    int a[1024] = {0};
    int n = 0;
    int i = 0;
    int j = 0;
    int v = 0;
    scanf("%d", &n);
    // printf("n=%d\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // printf("%d\n", a[i]);
    }
    for (i = 1; i < n; i++) {
        print_list(a, n);
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
    print_list(a, n);
    return 0;
}
