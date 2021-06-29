#include<stdio.h>
#define N 100
int main(){
    int n,i,j,a[N],key;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
        if( i != 0 ) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    for( i = 1 ; i < n ; i++ ){
        key = a[i];
        for( j = i - 1 ; j >= 0 ; j-- ){
            if( key > a[j] ) break;
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
        for( j = 0 ; j < n ; j++ ){
            if( j != 0 ) printf(" ");
            printf("%d",a[j]);
        }
        printf("\n");
    }
    return 0;
}
