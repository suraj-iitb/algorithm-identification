#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,q,*S,T,cnt = 0;
    scanf("%d",&n);
    S = malloc(sizeof(int) * n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for( i = 0 ; i < q ; i++ ){
        scanf("%d",&T);
        for( j = 0 ; j < n ; j++ ){
            if( T == S[j] ){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
