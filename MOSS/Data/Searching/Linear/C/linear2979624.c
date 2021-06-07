#include <stdio.h>

int main(){
    int n, q, T;
    int S[10000];
    scanf("%d\n",&n);
    for ( int ix = 0 ; ix < n ; ix++){
        if ( ix == n-1 ) scanf("%d\n",&S[ix]);
        else scanf("%d ",&S[ix]);
    }
    scanf("%d\n",&q);
    int counter = 0;
    for ( int ix = 0 ; ix < q ; ix++){
        if ( ix == q-1 ) scanf("%d\n",&T);
        else scanf("%d ",&T);
        int jx = 0;
        while ( jx < n ){
            if ( T == S[jx] ){
                ++counter;
                break;
            }
            jx++;
        }
    }
    printf("%d\n",counter);
    
    return 0;
}
