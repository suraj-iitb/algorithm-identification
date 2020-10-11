#include <stdio.h>
int main(void){
    int n , a[100] ;
    int i , j , t , l = 0 ;
    int flag ;
    
    scanf("%d" , &n) ;
    
    for(i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]) ;
    }
    
    for(i = 0 ; i < n ; i++){
        for(j = n - 1 ; j > i ; j--){
            if(a[j] < a[j - 1]){
                t = a[j - 1] ;
                a[j - 1] = a[j] ;
                a[j] = t ;
                l++ ;
            }
        }
    }
    
    for(i = 0 ; i < n ; i++){
        printf("%d" , a[i]) ;
        if(i == n - 1)continue ;
        printf(" ") ;
    }
    printf("\n") ;
    printf("%d\n" , l) ;
    return 0 ;
}
