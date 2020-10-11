#include<stdio.h>


int main(){
    int a[128], b, i,  j, temp, count, min, number;
    
    scanf("%d", &b);
    
    for(i = 0; i < b; i++){
        scanf("%d", &a[i]);
    }
    
    count = 0;
    
    for(i=0; i < b; i++){
        min = a[i];
        number = i;
        for(j = i; j < b; j++){
            if( min > a[j]){
                min = a[j];
                number = j;
            }
        }
        if(i != number){
            temp = a[i];
            a[i] = a[number];
            a[number] = temp;
            count++;
        }
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

