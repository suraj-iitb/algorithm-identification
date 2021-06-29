#include <stdio.h>

#define Num 100

int main(void){

    int l, n, i, k, j = 1, count = 0;
    int a[Num];

    scanf("%d", &l); 

    for (i = 0; i <= l-1; i++) {
        scanf("%d", &a[i]); 
    }

    while (j > 0) {
        j = 0;
        for (i = l-1; i >= 1; i--) {
            if(a[i-1] > a[i]){
                n = a[i-1];
                a[i-1] = a[i];
                a[i] = n;
                j = 1;
                count++;
            }
        }
    }
    
    for (i = 0; i <= l-2; i++) {
        printf("%d ", a[i]); 
    }
    printf("%d\n", a[i]);
    printf("%d\n", count);

    return 0;
}
