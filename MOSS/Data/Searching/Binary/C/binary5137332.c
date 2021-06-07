#include<stdio.h>
#define N 100000

int main(){
    int n,m,i,j,key,cnt = 0,a[N],flag;
    int left,right,mid;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
    scanf("%d",&m);
    for( i = 0 ; i < m ; i++ ){
        flag = 1;
        scanf("%d",&key);
        left = 0;
        right = n;
        while( left < right ){
            mid = (right + left) / 2;
            if( a[mid] == key ){
                flag = 0;
                break;
            }
            else if( key < a[mid] ){
                right = mid;
            }
            else left = mid + 1;
        }
        if( flag == 0 ) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

