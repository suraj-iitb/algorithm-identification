#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    int a[101];
    int i, j;
    int tmp;
    int cnt = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            if (a[j - 1] > a[j]){
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
                cnt++;
            }
        }
    }

    for (i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf ("%d\n", a[n - 1]);
    printf("%d\n", cnt);

    return (0);
}
