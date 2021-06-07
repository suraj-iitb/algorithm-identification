#include<stdio.h>
#define N 10000
int main(){
    int n,m,i,j,a[N],key,cnt = 0;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
    scanf("%d",&m);
    for( i = 0 ; i < m ; i++ ){
        scanf("%d",&key);
        for( j = 0 ; j < n ; j++ ){
            if( a[j] == key ){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
