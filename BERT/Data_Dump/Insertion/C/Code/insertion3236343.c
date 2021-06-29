#include <stdio.h>

#define Num 100

int main(void){

    int l, n, i, j, k;
    int a[Num];

    scanf("%d", &l); 

    for (i = 0; i <= l-1; i++) {
        scanf("%d", &a[i]); 
    }

    for (i = 0; i <= l-1; i++) {
        j = i - 1;
        while (j>=0){
            if(a[j] > a[j+1]){
                n = a[j+1];
                a[j+1] = a[j];
                a[j] = n;
            }
            j--; 
        }
        for (k = 0; k <= l-2; k++) {
            printf("%d ", a[k]);
        }
        printf("%d\n", a[k]);
    }

    return 0;
}
