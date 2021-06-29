#include<stdio.h>
#define N 100
int main(){
    int n,i,j,a[N],cnt = 0,min,key;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
    for( i = 0 ; i < n ; i++ ){
        min = i;
        for( j = i ; j < n ; j++ ){
            if( a[min] > a[j] ) min = j;
        }
        if( min != i ){
            key = a[min];
            a[min] = a[i];
            a[i] = key;
            cnt++;
        }
    }
    for( i = 0 ; i < n ; i++ ){
        if( i != 0 ) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
