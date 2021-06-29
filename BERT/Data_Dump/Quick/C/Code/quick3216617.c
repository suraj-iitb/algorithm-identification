#include <stdio.h>

struct elem{
    int i;
    int v;
};

int partition(
        struct elem* ary,
        int p, int r)
{
    int i =0;
    int j = 0;
    struct elem x, buf;
    x = ary[r];
    i = p;
    for (j = p; j < r; j++) {
        if (ary[j].v <= x.v) {
            buf = ary[j];
            ary[j] = ary[i];
            ary[i] = buf;
            i++;
        }
    }
    buf = x;
    ary[r] = ary[i];
    ary[i] = buf;
    return i;
}

void quick_arg_sort_impl(
        struct elem *ary,
        const int p,
        const int r
        )
{
    int q = 0;
    if (p < r) {
        q = partition(ary, p, r);
        quick_arg_sort_impl(ary, p, q -1);
        quick_arg_sort_impl(ary, q + 1, r);
    }
}

void quick_arg_sort(
        const int *ary,
        const  int ary_size,
        struct elem *sorted
        )
{
    int i = 0;
    for (i = 0; i < ary_size; i++) {
        sorted[i].i = i;
        sorted[i].v = ary[i];
    }
    /* TODO: ゼロ埋め処理*/
    quick_arg_sort_impl(sorted, 0, ary_size - 1);
}

int Y[100100];
struct elem A[100100];
char K[100100];
int main() {
    int i, n, k;
    int flag = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d", K+i, Y+i);
    }
    quick_arg_sort(Y, n, A);
    for (i = 0; i < n; i++) {
        if ((A[i].v == A[i-1].v) && (A[i].i<A[i-1].i)) {
            flag = 1;
        }
    }

    if (flag) {
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }
    for (i = 0; i < n; i++) {
        printf("%c %d\n", K[A[i].i], A[i].v);
    }
    return 0;
}
