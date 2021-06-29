#include <stdio.h>
int main(void){
    int n , a[105] ;
    int i , j , t , m , l = 0 ;
    
    scanf("%d" , &n) ;
    
    for(i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]) ;
    }
    
    for(i = 0 ; i < n ; i++){
        m = i ;
        for(j = i ; j < n ; j++){
            if(a[j] < a[m]){
                m = j ;
            }
        }
        if(a[m] != a[i]){
            t = a[i] ;
            a[i] = a[m] ;
            a[m] = t ;
            l++ ;
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
