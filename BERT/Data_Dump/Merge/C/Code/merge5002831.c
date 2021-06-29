#include <stdio.h>

const int INF = 0x3f3f3f3f;
int ans, a[500005], t[500005];

void ms(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    ms(l, mid); ms(mid + 1, r);
    int tl = l, tr = mid + 1, cnt = l;
    while (tl <= mid && tr <= r) {
        if (a[tl] <= a[tr])
            t[cnt++] = a[tl++];
        else 
            t[cnt++] = a[tr++];
        ans++;
    }
    ans += mid - tl + r - tr + 2;
    while (tl <= mid)
        t[cnt++] = a[tl++];
    while (tr <= r)
        t[cnt++] = a[tr++];
    for (int i = l; i <= r; i++)
        a[i] = t[i];
    return;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    ms(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n - 1)
            printf("\n");
        else 
            printf(" ");
    }
    printf("%d\n", ans);
}
