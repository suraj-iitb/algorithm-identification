#include<stdio.h>
int main(){
    int i, j, k, m, n, l, r, c = 0;
    scanf("%d", &n);
    int A[n];
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &k);
    int B[k];
    for(i = 0; i < k; i++) scanf("%d", &B[i]);
    
    for(j = 0; j < k; j++){
         l = 0;
         r = n;
    while (l < r) {
    m = (l + r) / 2;
        if (A[m] == B[j]) c++;
        if (A[m] == B[j]) break;
        if (B[j] < A[m]) r = m;
        else l = m + 1;
    }
    }
    printf("%d\n", c);
    return 0;
    }

