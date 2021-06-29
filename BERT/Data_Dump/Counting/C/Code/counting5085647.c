#include <stdio.h>
#define MAX 2000001
#define VMAX 10001

int c[VMAX],a[MAX],b[MAX],n;

void countingsort(void);

int main() {
    int i;
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&a[i]);
    }
    countingsort();
    for ( i = 0 ; i < n ; i++ ){
        printf("%d",b[i]);
        if ( i < n - 1 ) printf(" ");
    }
    printf("\n");
    return 0;
}

void countingsort(){
    int i;
    for ( i = 0 ; i < VMAX ; i++ ) {
        c[i] = 0;
    }
    for ( i = 0 ; i < n ; i++ ) {
        c[a[i]]++;
    }
    for ( i = 1 ; i < VMAX ; i++ ) {
        c[i] = c[i] + c[i - 1];
    }
    for ( i = n - 1 ; i >= 0 ; i-- ) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}
