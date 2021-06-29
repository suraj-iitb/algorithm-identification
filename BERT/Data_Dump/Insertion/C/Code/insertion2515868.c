#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int n, int *a){
    int k;
    for (k = 0; k < n - 1; k++){
        printf("%d ", a[k]);
    }
    printf("%d\n", a[n - 1]);
}

int main(void){
    int n;
    int *a;
    int i, j;
    int tmp;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++){
        tmp = a[i];
        j = i - 1;
        show(n, a);
        while (tmp < a[j] && j >= 0){
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }    
    }
    show(n, a);
    return 0;
}
