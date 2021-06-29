#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, n, key, *a;
    scanf("%d", &n);
    a = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        printf("%d", a[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        for(j = 0; j < n; j++) {
            printf("%d", a[j]);
            if(j < n - 1) printf(" ");
        }
        printf("\n");
    }
    free(a);
    return 0;
}





