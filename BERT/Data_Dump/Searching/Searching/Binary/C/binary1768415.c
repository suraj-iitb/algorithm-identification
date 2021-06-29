#include <stdio.h>

int main(){
    int i,n,q;
    int l, r, m;
    int count = 0;
    int S[100000],T[50000];
 
    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for( i=0; i<q; i++ ){
        scanf("%d", &T[i]);
    }
    for( i=0; i<q; i++ ){
        l=0;
        r=n;
        while( l<r ){
            m=(l+r)/2;
            if( S[m]==T[i] ){
                count++;
                break;
            }
            else if( T[i]<S[m] ) r=m;
            else if( T[i]>S[m] ) l=m+1;
        }
    }
    printf("%d\n", count);
    return 0;
}