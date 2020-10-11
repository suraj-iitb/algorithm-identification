#include <stdio.h>

int main(void)
{
    int n, a[101];
    int i, j, tmp;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d", a[j]);
            if (j < n - 1){
                printf(" ");
            }
        }
        printf("\n");
        tmp = a[i];
        j =  i - 1;
        while (j >= 0 && a[j] > tmp){
            a[j + 1] = a[j];
            j--;
            a[j + 1] = tmp;
        }
    }

    for (i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);

    return (0);
}
