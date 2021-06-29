#include <stdio.h>

int binarySearch(int n, int *s, int key) {
    int r,l;
    l = 0;
    r = n;
    while( r > l+1 ) {
        int m = ( r + l )/2;
        if ( s[m] >  key ) r = m;
        else l = m;
    }
    return s[l] == key;
}


int main(){
    int cou = 0;
    int n;
    int i,s[100000];

    scanf("%d",&n);
    for(i = 0;i < n;i++ ) {
        scanf("%d",&s[i]);
    }

    int q;
    int t;

    scanf("%d",&q);
    for(i = 0; i < q; i++) {
        scanf("%d",&t);
        cou += binarySearch(n,s,t);
    }

    printf("%d\n",cou);
    return 0;
}

