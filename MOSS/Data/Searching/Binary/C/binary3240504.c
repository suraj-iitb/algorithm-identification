#include <stdio.h>

int binarysearch (int key, int n, int a[]) {
    int left = 0;
    int right = n;
    int mid;

    while ( left < right ) {
        mid = (left + right) / 2;
        if ( a[mid] == key ) {
            return 1;
        }
        else if ( key < a[mid] ) {
            right = mid;
        }
        else
            left = mid + 1;
        }
        return 0;
    }

int main () {
    int n, q, i, key;
    int s[200000];
    int c = 0;
    
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &s[i]);
    }

    scanf("%d", &q);
    for ( i = 0; i < q; i++ ) {
        scanf("%d", &key);
        if ( binarysearch(key, n, s) )
        c++;
        }
    
    printf("%d\n", c);

    return 0;
}
