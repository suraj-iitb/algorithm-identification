#include <stdio.h>
int main(void){
    int n ;
    scanf("%d" , &n) ;
    int str[n] ;
    int i , j , k , v ;
    
    for(i = 0 ; i < n ; i++){
        scanf("%d" , &str[i]) ;
    }
    
    for(i = 0 ; i < n ; i++){
        v = str[i] ;
        j = i - 1 ;
        while(j >= 0  &&  str[j] > v){
            str[j + 1] = str[j] ;
            j-- ;
        }
        str[j + 1] = v ;
        for(k = 0 ; k < n ; k++){
            printf("%d" , str[k]) ;
            if(k < n - 1){
                printf(" ") ;
            }
        }
        printf("\n") ;
    }
    return 0 ;
}
