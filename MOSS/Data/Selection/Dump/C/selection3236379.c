#include <stdio.h>

#define Num 100

int main(void){

    int l, n, i, j, k = 0, min = 0, count = 0;
    int a[Num];

    scanf("%d", &l); 

    for (i = 0; i <= l-1; i++) {
        scanf("%d", &a[i]); 
    }

    for (i = 0; i <= l-1; i++) {
        min = i;
        for (j = i+1; j <= l-1; j++) {
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            k = a[min];
            a[min] = a[i];
            a[i] = k;
            count++;
        }
    }
    
    for (i = 0; i <= l-2; i++) {
        printf("%d ", a[i]); 
    }
    printf("%d\n", a[i]);
    printf("%d\n", count);

    return 0;
}
