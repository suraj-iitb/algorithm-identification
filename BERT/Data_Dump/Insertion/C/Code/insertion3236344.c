#include<stdio.h>


int main(){
    int a[128], b, i, x, k,  j, temp;
    
    scanf("%d", &b);
    
    for(i = 0; i < b; i++){
        scanf("%d", &a[i]);
    }
    
    for(k=1; k < b; k++){
            for( i = 0; i < b; i++){
        
               if(i != 0){
                    printf(" ");
                 }
                printf("%d", a[i]);
             }
            putchar('\n');
            
            x = a[k]; 
            
            j = k- 1;
            
           while(j >= 0 && a[j] > x){
                a[j + 1] = a[j];
                j--;
            }             
            a[j + 1] = x;
          
  }
    
     for( i = 0; i < b; i++){
        
         if(i != 0){
            printf(" ");
         }
        
        printf("%d", a[i]);
         }
        putchar('\n');
    return 0;
}

