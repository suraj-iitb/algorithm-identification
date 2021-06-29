#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr1, *arr2;

    int arr3[200000];
    int n, i, j;
    scanf("%d", &n);

    arr1 = malloc(sizeof(int)*n+1);
    arr2 = malloc(sizeof(int)*n+1);

    for(i = 0; i <= 10000; i++){
        arr3[i] = 0;
    }

    for(i = 0; i < n; i++){
        scanf("%d", &arr1[i+1]);
        arr3[arr1[i+1]]++;
    }

    for(i = 1; i <= 200000; i++){
        arr3[i] = arr3[i]+arr3[i-1];
    }
    for(j = 1; j <= n; j++){
        arr2[arr3[arr1[j]]] = arr1[j];
        arr3[arr1[j]]--;
    }

    for(i = 1; i <= n; i++){
        if(i > 1){
            printf(" ");
        }
        printf("%d", arr2[i]);
    }
    printf("\n");

    return 0;
}
