#include <stdio.h>
#define N 2000002
 
void counting(int[], int[], int);
int n;
int b[N];
int c[N];
 
int main() {
    int i;
    int a[N];
    int max;
 
    scanf("%d", &n);
    for(i = 1; i < n+1; i++) {
        scanf("%d", &a[i]);
    }
 
    max = a[0];
    i = 1;
    while(i < n+1) {
        if(max < a[i]) max = a[i];
        i++;
    }
 
    counting(a, b, max);
 
    return 0;
}
 
void counting(int a[], int b[], int k) {
    int i;
 
 
    for (i = 0; i < n; i++) {
        c[i] = 0;
    }
    for (i = 1; i < n+1; i++) {       // 出現数
        c[a[i]]++;
    }
    for (i = 1; i < k+1; i++) {       // 足していく
        c[i] += c[i-1];
    }
    for (i = n; i > 0; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for (i = 1; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("%d\n", b[n]);
}
