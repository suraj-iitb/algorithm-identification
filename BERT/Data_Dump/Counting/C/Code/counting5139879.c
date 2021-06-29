#include<stdio.h>
#define N 2000000
int main(){
    int n,i;
    int a[N+1],b[N+1],c[N+1];
    for( i = 0 ; i < N ; i++ ) c[i] = 0;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    for( i = 1 ; i < N ; i++ ) c[i] = c[i] + c[i - 1];
    for( i = 0 ; i < n ; i++ ){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for( i = 1 ; i < n + 1 ; i++ ){
        if( i != 1 ) printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}
