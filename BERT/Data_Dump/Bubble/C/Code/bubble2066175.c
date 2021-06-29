#include <stdio.h>
 
int main()
{
    int a[100], n, i, j, x;
    int c = 0;
 
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j-1]) {
                x = a[j];
                a[j] = a[j-1];
                a[j-1] = x;
                c += 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("%d\n", c);
 
    return 0;
}
