#include <stdio.h>

int main (void){
    int n, i, j, temp, count = 0;
    scanf("%d", &n);
    int r[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
    
    for(i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            
            if(r[j] < r[j-1]){
                temp = r[j];
                r[j] = r[j-1];
                r[j-1] = temp;
                count = count + 1;
            }    
        }
    }
    
    for(i = 0; i < n; i++){
        printf("%d", r[i]);
        if(i != n-1) printf(" ");
        
    }
    
    puts("");
    printf("%d\n", count);

    return 0;    
}
