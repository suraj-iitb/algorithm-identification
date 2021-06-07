#include <stdio.h>

int main () {
    int s[20000], t[900];
    int n, q, i, j, key;
    int c = 0;

    scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ) { 
        scanf("%d", &s[i]);
    }
    
    scanf("%d", &q);

    for ( i = 0; i < q; i++ ) { 
        scanf("%d", &t[i]);
    }

    for ( j = 0; j < q; j++ ) {
        i = 0;
        key = t[j];
        s[n] = key;
        while ( s[i] != key ) {
            i++;
        }

        if ( i != n ) {
            c++;
        }
    }
    
    printf("%d\n", c);

    return 0;
}
