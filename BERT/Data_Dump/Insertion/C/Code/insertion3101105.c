#include <stdio.h>
int main(void){
    int n = 0, i, j, k, v;
    int a[100];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("%d",a[0]);
        for(k = 1; k < n; k++) {
            printf(" %d",a[k]);
        }
    printf("\n");
        
    for(i = 1; i <= n-1; i++) {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = v;
        
        printf("%d",a[0]);
        for(k = 1; k < n; k++) {
            printf(" %d",a[k]);
        }
        printf("\n");
    }
    return 0;
}
