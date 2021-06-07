#include <stdio.h>

int linearSearch(int a[], int n, int key)
{
    int i = 0;

    a[n] = key;
    while ( a[i] != key ) {
        i++;
    }
    return i != n;
}

int main(void)
{
    int n;
    int q;
    int s[10001];
    int t[501];
    int cnt = 0;

    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &s[i]);
    }

    scanf("%d", &q);

    for ( int i = 0; i < q; i++ ) {
        scanf("%d", &t[i]);
    }

    for ( int i = 0; i < q; i++ ) {
        cnt += linearSearch(s, n, t[i]);
    }

    printf("%d\n", cnt);

    return 0;
}
