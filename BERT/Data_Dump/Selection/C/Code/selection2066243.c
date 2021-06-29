#include <stdio.h>
 
int main()
{
    int a[100], n, i, j, mini, x;
    int c = 0;
 
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    for (i = 0; i < n; i++) {
        mini = i;
        for (j = i; j < n; j++) {
            if (a[j] < a[mini])
                mini = j;
        }
        if (mini != i) {
            x = a[i];
            a[i] = a[mini];
            a[mini] = x;
            c += 1;
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
