#include <stdio.h>
#define N 100

int main(void) {
    int i, j, n, v; 
    int a[N];

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &v);
        if( 0<=v && v<= 1000 ){
            a[i] = v;
        }
        else i--;
    }

    for(i=0; i<n; i++) {
        v = a[i];
        j = i-1;

        while( j>=0 && a[j] > v ) {
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }

        for(j=0; j<n; j++){
            if( j<n-1 ) printf("%d ", a[j]);
            else printf("%d\n", a[j]);
        }

    }

    return 0;
}
