#include <stdio.h>

int main() {
    
    int n,i,j ,minj, a[100], t, c;
    c = 0;
    scanf("%d", &n);
    
    
    for (i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n; ++i){
        minj = i;
        for (j = i; j < n; ++j){
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i){
            t = a[i];
            a[i] = a[minj];
            a[minj] = t;
            c=c+1;
        }
    }
    
    for (i = 0; i < n; ++i){
        printf("%d",a[i]);
        if(i != n-1)putchar(' ');
    }
    
    putchar('\n');
    printf("%d\n", c);
    
    return 0;
    

}
