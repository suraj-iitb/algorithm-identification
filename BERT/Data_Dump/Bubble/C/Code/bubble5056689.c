#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, temp, n, *a, count = 0, flag = 1;
    
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    while(flag == 1) {
        flag = 0;
        for(i = n - 1; i > 0; i--) {
            if(a[i] < a[i - 1]) {
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                count++;
                flag = 1;
            }
        }
    }
    for(i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i < n - 1) printf(" ");
    }
    
    free(a);    
    printf("\n%d\n", count);
    
    return 0;
}

