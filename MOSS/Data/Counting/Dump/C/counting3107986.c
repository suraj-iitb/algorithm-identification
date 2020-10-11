#include <stdio.h>
#include <stdlib.h>
#define N 10001
int c[N];
int main(){
    for(int i = 0; i <= N; i++) c[i] = 0;
    int n;
    scanf("%d", &n);
    int a[n+1];
    int b[n+1];

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        c[a[i]]++;
    }
    for(int i = 1; i <= N; i++) c[i] += c[i-1];

    for(int j = n; j >= 1; j--){
        b[c[a[j]]] = a[j];
        c[a[j]] --;
    }

    for(int j = 1; j <= n; j++){
        if(j != n) printf("%d ", b[j]);
        else printf("%d\n", b[j]);
    }
    return 0;
}
