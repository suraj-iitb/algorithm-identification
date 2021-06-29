#include <stdio.h>

int main() {
    
    int a[1000];
    int n, i, v, j;
    
    scanf("%d", &n);
    
    
    for (i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    
    for (j = 0; j < n; ++j){
        printf("%d",a[j]);
        if (j != n-1) {
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }

    
    for (i = 1; i < n; ++i){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        for (j = 0; j < n; ++j){
            printf("%d",a[j]);
            if (j != n-1) {
                putchar(' ');
            }
            else{
                putchar('\n');
            }
        }
    }
    
}
