#include<stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[2000000] = {0};
    int c[10000] = {0};
    int max = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] > max) max = a[i];
        c[a[i]]++;
    }
    for (int i = 1; i <= max; i++){
        c[i] += c[i-1];
    }
    int b[2000000] = {0};
    for (int i = n-1; i >= 0; i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    for (int i = 0; i < n-1; i++) printf("%d ", b[i]);
    printf("%d\n", b[n-1]);
}
