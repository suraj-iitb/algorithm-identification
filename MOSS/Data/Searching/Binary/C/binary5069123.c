#include<stdio.h>
#include<stdlib.h>

int *S,n;

int binary(int);

int main(){
    int i,q,T,cnt = 0;
    scanf("%d",&n);
    S = malloc(sizeof(int) * n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for( i = 0 ; i < q ; i++ ){
        scanf("%d",&T);
        if(binary(T) == 1) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

int binary(int a){
    int left = 0,right = n,mid;
    while( left < right ){
        mid = (left + right) / 2;
        if( a == S[mid]) return 1;
        else if( a < S[mid] ) right = mid;
        else left = mid + 1;
    }
    return 0;
}
