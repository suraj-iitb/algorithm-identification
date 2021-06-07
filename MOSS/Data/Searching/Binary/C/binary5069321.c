#include<stdio.h>
#include<stdlib.h>

int *s,n;

int binary(int);

int main(){
    int i,q,T,cnt = 0;
    scanf("%d",&n);
    s=malloc(sizeof(int) * n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&s[i]);
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
  int left = 0;
  int right = n;
  int mid;
    while( left < right ){
        mid = (left + right)/2;
        if( a == s[mid]) return 1;
        else if( a < s[mid] ) right=mid;
        else left = mid +1;
    }
    return 0;
}

