#include<stdio.h>

int main(){
    int m, i, j, k, n, c, count, flag;
    int a[100];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    i = 0;
    flag = 1;
    while(flag != 0){
        flag = 0;
        for(j = n -1; j > i; j--){
            if(a[j] < a[j-1]){
                c = a[j];
                a[j] = a[j-1];
                a[j-1]  = c;
                count++;
                flag = 1;
            }
        }
        i++;
    }
    
    printf("%d", a[0]);
    for(k = 1; k < n; k++){
        printf(" %d", a[k]);
    }
    printf("\n");
    printf("%d\n", count);
    
    return 0;
}
