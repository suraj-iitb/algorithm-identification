#include<stdio.h>

int main(){
    int i, j, n, c, count = 0, minj;
    int a[100];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            count++;
            c = a[minj];
            a[minj] = a[i];
            a[i] = c;
        }
    }

    printf("%d", a[0]);
    for(i = 1; i < n; i++){
        printf(" %d", a[i]);
    }
    printf("\n");
    printf("%d\n", count);
    
    return 0;
}
