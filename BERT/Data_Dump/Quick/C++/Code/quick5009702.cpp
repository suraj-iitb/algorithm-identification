#include <stdio.h>

typedef struct cd{
    char c;
    int num;
} cd;

cd a[100005], b[100005], t[100005];

void ms(int l, int r) {
    // printf("%d %d\n", l, r);
    if (l >= r) return;
    int mid = (l + r) / 2;
    ms(l, mid); ms(mid + 1, r);
    int tl = l, tr = mid + 1, cnt = l;
    while (tl <= mid && tr <= r) {
        if (a[tl].num <= a[tr].num)
            t[cnt++] = a[tl++];
        else 
            t[cnt++] = a[tr++];
    }
    while (tl <= mid)
        t[cnt++] = a[tl++];
    while (tr <= r)
        t[cnt++] = a[tr++];
    for (int i = l; i <= r; i++)
        a[i] = t[i];
    return;
}

int n;

int partition(int p, int r) {
    // printf("%d %d\n\n", p, r);
    int x = b[r].num;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (b[j].num <= x) {
            i++;
            cd tt = b[i];
            b[i] = b[j], b[j] = tt;
        }
        
    }
    cd tt = b[i + 1];
    b[i + 1] = b[r], b[r] = tt;
    // for (int i = 0; i < n; i++) {
    //     printf("%c %d\n", b[i].c, b[i].num);
    // }
    return i + 1;
}

void qsort(int p, int r) {
    if (p >= r) return;
    int q = partition(p, r);
    qsort(p, q - 1);
    qsort(q + 1, r);
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c %d", &a[i].c, &a[i].num);
        b[i] = a[i];
        getchar();
    }
    qsort(0, n - 1);
    ms(0, n - 1);
    int st = 1;
    for (int i = 0; i < n; i++) {
        // printf("%c %d\n", a[i].c, a[i].num);
        if (a[i].c != b[i].c) st = 0;
    }
    if (st) printf("Stable\n");
    else printf("Not stable\n");
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", b[i].c, b[i].num);
    }
}
