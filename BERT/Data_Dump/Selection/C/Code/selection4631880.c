#include<stdio.h>
#define SIZE 100

int main(void)
{
    int i, j, minj, n, tmp, cnt, a[SIZE];
    
    scanf("%d", &n);
    for ( i=0; i<n; ++i)
        scanf("%d", &a[i]);
    
    cnt = 0;
    for ( i=0; i<n; ++i) {
        minj = i;
        for ( j=i; j<n; ++j) {
            if ( a[minj] > a[j])
                minj = j;
        }
        if ( i != minj) {
            tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            ++cnt;
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
