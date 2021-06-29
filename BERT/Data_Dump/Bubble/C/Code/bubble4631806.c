#include<stdio.h>
#define SIZE 100

int main(void)
{
    int i, j, n, tmp, cnt, a[SIZE];
    
    scanf("%d", &n);
    for ( i=0; i<n; ++i)
        scanf("%d", &a[i]);
    
    cnt = 0;
    for ( i=0; i<n; ++i) {
        for ( j=n-1; j>i; --j) {
            if ( a[j-1] > a[j]) {
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                ++cnt;
            }
        }
    }
    
    for ( i=0; i<n; ++i) {
        printf("%d", a[i]);
        if ( i != n-1)
            putchar(' ');
    }
    putchar('\n');
    printf("%d\n", cnt);
    
    return 0;
}
