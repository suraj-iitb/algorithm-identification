#include <stdio.h>
#define MAX 100000

int n, S[MAX];

int search(int key){
    int left = 0;
    int right = n;
    while ( left < right ){
        int mid = (left+right) / 2;
        if ( S[mid] == key ) return 1;
        else if ( S[mid] > key ) right = mid;
        else left = mid+1;
    }
    return 0;
}

int main(){
    int i, q, T, C;
    
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &S[i]);
    scanf("%d", &q);
    for ( i = 0; i < q; i++ ){
        scanf("%d", &T);
        if( search(T) ) C++;
    }
    printf("%d\n", C);
    return 0;
}
