#include <stdio.h>
int main (void){
    int n, i, j, temp, count = 0, min = 9999999, flag = -1;
    scanf("%d", &n);
    int r[n];

    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(r[j] < min){
                min = r[j];
                flag = j;
            }
            if(min < r[i] && j == n-1){
                temp = r[flag];
                r[flag] = r[i];
                r[i] = temp;
                count = count + 1;
            }
         
        
            
        }
        min = 9999999;
    }
    for(i = 0; i < n; i++){
        printf("%d", r[i]);
        if(i != n-1) printf(" ");
    }
    puts("");
    printf("%d\n", count);
    return 0;
}
