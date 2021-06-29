#include <stdio.h>

int main (void){
    int n, i, j, temp;
    
    scanf("%d", &n);
    
    int r[n];
    
    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
    
    for(i = 0; i < n; i++){
        for(j = i; j > 0; j--){
            if(r[j] < r[j-1]){
            temp = r[j];
            r[j] = r[j-1];
            r[j-1] = temp;
            }
        }
        for(j = 0; j < n; j++){
            printf("%d", r[j]);
            if(n - j != 1) printf(" ");
        }
        puts("");
    }
    return 0;
}
