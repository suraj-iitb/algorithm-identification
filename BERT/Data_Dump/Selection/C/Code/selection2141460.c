#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, a[101];
    int i, j;
    int min, tmp;
    int cnt = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        if (min != i){
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
            cnt++;
        }
    }

    for (i = 0; i < n; i++){
        printf("%d", a[i]);
        if (i != n - 1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", cnt);

    return (0);
}
