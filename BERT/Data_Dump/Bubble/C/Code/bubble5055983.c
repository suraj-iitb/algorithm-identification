#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, tmp, k = 0, flag = 1;
    int *a;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(flag){
     flag = 0;
     for(i = n-1; i > 0; i--){
       if( a[i] < a[i-1]){
        tmp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tmp;  
        flag = 1;
        k++;
       }
     }
    }
    for(i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n", a[n - 1], k);
    free(a);
    return 0;
}
