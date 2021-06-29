#include<stdio.h>
#define N 100
int main(){
    int i,j,n,a[N],key,cnt = 0;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    for( i = 0 ; i < n ; i++ ){
        for( j = n - 1 ; j >= 1 ; j-- ){
            if( a[j - 1] > a[j] ){
                key = a[j];
                a[j] = a[j - 1];
                a[j - 1] = key;
                cnt++;
            }
        }
    }
    for( i = 0 ; i < n ; i++ ){
        if( i != 0 ) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
