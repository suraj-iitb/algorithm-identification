#include <stdio.h>
#define MAX 10000

int search(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    while ( A[i] != key ) i++;
    return i != n;
}

int main(){
    int i, n, q, T, C=0;
    int S[MAX];

    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &S[i]);
    scanf("%d", &q);
    for ( i = 0; i < q; i++ ){
        scanf("%d", &T);
        if ( search(S, n, T) ) C++;
    }
    printf("%d\n", C);
    return 0;
}
