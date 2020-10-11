#include<stdio.h>


int main(){
    int a[128], b, i,  j, count, temp, flag, times;
    
    scanf("%d", &b);
    
    for(i = 0; i < b; i++){
        scanf("%d", &a[i]);
    }
    times = b;
    count = 0;
    flag = 1;    
    while(flag){
        flag = 0;
        for (j = 0; j < times-1; j++){
            if ( a[ j ]  > a[j +1] ) {
                temp = a[j];
                a[j] = a[j +1];
                a[j + 1] = temp;
                count++;
                flag = 1;
                } 
        }
        times--;
    }
    for( i = 0; i < b; i++){
        
        if(i != 0){
            printf(" ");
        }
        
        printf("%d", a[i]);
    }
        
    printf("\n%d\n", count);
    
    return 0;
}

