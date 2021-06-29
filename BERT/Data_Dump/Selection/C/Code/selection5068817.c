#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, x[100], temp, change = 0;
    int i, j, minj;

    scanf("%d", &n);
    if(n < 1 || n > 100){
        exit(1);
    }

    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
        if(x[i] < 0 || x[i] > 100){
            exit(2);
        }
    }

    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(x[j] < x[minj]){
                minj = j;
            }
        }
        if(x[i] > x[minj]){
            temp = x[minj];
            x[minj] = x[i];
            x[i] = temp;
            change++;
        }
    }

    for(i = 0; i < n-1; i++){
        printf("%d ", x[i]);
    }
    printf("%d\n%d\n", x[n-1], change);

    return 0;
}
