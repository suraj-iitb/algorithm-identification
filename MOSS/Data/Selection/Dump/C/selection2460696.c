#include<stdio.h>
int main(){
    int n, i, j, min, tmp, data[101]={}, count=0;

    scanf("%d", &n);
    for( i = 0; i < n; i++ ){
        scanf("%d", &data[i]);
    }
    for( i = 0; i < n - 1; i++ ){
        min = i;
        for( j = i; j < n; j++ ){
            if( data[j] < data[min] ){
                min = j;
            }
        }
        tmp = data[i];
        data[i] = data[min];
        data[min] = tmp;
        if( i != min ) count++;
    }
    for( i = 0; i < n; i++ ){
        printf("%d", data[i]);
        if( i != n - 1 ){
            printf(" ");
        }
    }
    printf("\n%d\n", count);
    return 0;
}
