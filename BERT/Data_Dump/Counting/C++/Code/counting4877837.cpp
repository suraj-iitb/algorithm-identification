#include<bits/stdc++.h>
#define MAX 2000001
#define VMAX 10000

int main(int argc, char *argv[]){
    unsigned short *a, *b;

    int c[VMAX + 1];
    int n, i, j;
    scanf("%d", &n);

    a = (unsigned short*)malloc(sizeof(short)*n + 1);
    b = (unsigned short*)malloc(sizeof(short)*n + 1);

    for(i=0; i<VMAX; i++)
        c[i] = 0;
    for(i=0; i<n; i++){
        scanf("%hu", &a[i+1]);
        c[a[i+1]]++;
    }
    for(i=1; i<= VMAX; i++)
        c[i] = c[i] + c[i-1];
    for(j=1; j<=n; j++){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
    printf("%d", b[1]);
    for(i=2; i<=n; i++)
        printf(" %d", b[i]);
    printf("\n");

    return 0;
}
