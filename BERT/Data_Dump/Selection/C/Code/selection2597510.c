#include "stdio.h"


int main()
{
    int n, a[100], j, x, c, i, mini,d;
    scanf("%d", &n);
    
    c = 0;
    for (i = 0; i <= n - 1; i++)
        scanf("%d", &a[i]);

    i = 0;

    for (i = 0; i <= n - 1; i++) {
        mini = i;
        for (j = i; j <= n - 1; j++) {
            if (a[j] < a[mini]) {
                mini = j;
                d = 1;
        }
        }
        if (d == 1) {
            x = a[i];
            a[i] = a[mini];
            a[mini] = x;
            c++;
        }
        d = 0;
        }
    

    j = 0;
    for (j = 0; j < n - 1; j++)
        printf("%d ", a[j]);

    printf("%d\n", a[n - 1]);
    printf("%d\n", c);
    return 0;
}
