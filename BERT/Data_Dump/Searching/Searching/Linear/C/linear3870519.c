#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


static inline int find(int n, int target[], int len) {
    int i;
    
    for ( i = 0; i < len; i++ ) {
        if ( target[i] == n ) {
            return 1;
        }
    }

    return 0;
}

static void read_numbers(int array[], int num) {
    int i, d;

    for ( i = 0; i < num; i++ ) {
        scanf("%d", &d);
        array[i] = d;
        (void)fgetc(stdin);
    }

    return;
}

int main(int argc, char* argv[]) {
    int n, q, i;
    int* S;
    int* T;
    int C = 0;
    
    scanf("%d\n", &n);
    S = malloc( sizeof(int) * n );
    read_numbers(S, n);

    scanf("%d\n", &q);
    T = malloc( sizeof(int) * q );
    read_numbers(T, q);

    for ( i = 0; i < q; i++ ) {
        C += find(T[i], S, n);
    }

    printf("%d\n", C);

    return 0;
}

