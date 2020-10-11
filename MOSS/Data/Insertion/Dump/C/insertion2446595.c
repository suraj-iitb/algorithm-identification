#include<stdio.h>
int main(){
    int n ,a[1001]={}, i, j, tmp, k;
    scanf("%d", &n);
    for( i = 0; i < n ; i++){
        scanf("%d", &a[i]);
        if( i == n -1 ){
        printf("%d", a[i]);
        }else printf("%d ", a[i]);
    }
    printf("\n");
    for( i = 1; i < n; i++ ){
        tmp = a[i];
        j = i - 1;
        while( j >= 0 && a[j] > tmp ){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        for( k = 0; k < n; k++ ){
            if( k == n-1 ){
                printf("%d", a[k]);
            }else{
                printf("%d ", a[k]);
            }
        }
        printf("\n");
    }
    return 0;
}
