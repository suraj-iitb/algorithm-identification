#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, *a, minj, temp, count = 0;
    
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++) {
        minj = i;
        for(j = i; j < n; j++) {
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        if(i != minj) {
            temp = a[i];
            a[i] = a[minj];
            a[minj] = temp;
            count++;
        }
    }
    for(i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i != n - 1) printf(" ");
    }
    printf("\n%d\n", count);
    free(a);
    
    return 0;
}

