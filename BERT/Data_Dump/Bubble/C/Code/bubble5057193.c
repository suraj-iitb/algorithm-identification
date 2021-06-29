#include <stdio.h>

int main(void) {
    int n, i, j, k, swap, ans=0;
    int a[100];
    scanf("%d", &n);
    for(i=0;i<n;i+=1){
        scanf("%d", &a[i]);
    }
    for(j=0; j<n; j+=1){
        for(k=n-1; k>j; k-=1){
            if(a[k-1]>a[k]){
                ans += 1;
                swap = a[k-1];
                a[k-1] = a[k];
                a[k] = swap;
            }
        }
    }
    for(i=0;i<n;i+=1){
        printf("%d", a[i]);
        if (i<n-1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", ans);
    return 0;
}

