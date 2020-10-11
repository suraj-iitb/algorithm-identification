#include <stdio.h>

int main(){
    
    
    int n, i, flag, t, c;
    int a[100];
    scanf("%d", &n);
    
    flag = 1;
    c = 0;
    
    
    for (i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    
    while(flag) {
        flag = 0;
        
        for (i = n-1; i > 0; --i){
            if (a[i] < a[i-1]){
                t = a[i];
                a[i] = a[i-1];
                a[i-1] = t;
                flag = 1;
                c = c + 1;
            }
        }
    }
    
    for (i = 0; i < n; ++i){
        printf("%d",a[i]);
        if (i != n-1) {
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }
    
    printf("%d\n",c);
    
    return 0;
}
