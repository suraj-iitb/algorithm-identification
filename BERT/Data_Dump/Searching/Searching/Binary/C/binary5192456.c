#include <stdio.h>

int main(){
    int n,i,q,T,C = 0;
    int S[100000];

    scanf("%d",&n);
    for(i = 0; i <= n-1; i++ ) {
        scanf("%d",&S[i]);
    }

    scanf("%d",&q);
    for(i = 0; i < q; i++) {
        scanf("%d",&T);
        C += nlinearSearch(n,S,T);
    }

    printf("%d\n",C);
    
    return 0;
}

int nlinearSearch(int n, int *S, int key) {
    int r,l;
    
    r = n;
    l = 0; 
    
    while( r > l+1 ) {
        int m = ( r + l )/2;
        if ( S[m] >  key ) r = m;
        else l = m;
    }
    return S[l] == key;
}
