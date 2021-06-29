#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, key, *a, n, k;
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));

    for(i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
    for(k = 0;k < n;k++){
        printf("%d", a[k]);
        ((k < n-1)?printf(" "):printf("\n"));
    }

    for(i = 1;i < n;i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        } 
        a[j+1] = key;
        for(k = 0;k < n;k++){
            printf("%d", a[k]);
            ((k < n-1)?printf(" "):printf("\n"));
        }
    }

    return 0;
}
