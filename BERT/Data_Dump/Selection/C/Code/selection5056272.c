#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i,j, tmp, minj, k = 0, l = 0;
    int *a;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    
for(i =0; i < n - 1; i++){
    minj = i;
    for(j = i; j < n; j++){
        if(a[j] < a[minj]){
            minj =j;
            k++;
        }
        
    }
    if(k != 0){
        l++;
        k = 0;
    }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;        
    
}
    

    for(i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n", a[n - 1], l);
    free(a);
    return 0;
}
