#include<stdio.h>
int n, s[100000000], count = 0;
void binarySearch ( int key ) {
    int left = 0;
    int right = n;
    while ( left < right ) {
        int mid = (left + right) / 2;
        if ( key == s[mid] ) {
            count++;
            break;
        }
        else if ( key < s[mid] ) right = mid;
        else left = ++mid;
    }   
}

int main(void) {
    int i, j, q, t[500000];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for ( i = 0; i < q; i++ ) {
        scanf("%d", &t[i]);
        binarySearch(t[i]);
    }
    
    printf("%d\n", count);
    return 0;
}
