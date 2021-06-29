#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;

int ara[101] ;

int main()
{
    //freopen("tex.in" , "r" ,stdin) ;
    //freopen("tex.out" , "w" ,stdout) ;

    int i , j , item ;
    int n ;
    scanf("%d" ,&n) ;
    for(i = 0 ; i < n ; i++){
        scanf("%d" ,&ara[i]) ;
    }
    
    for(i = 0 ; i < n ; i++){

        item = ara[i] ;       
        j = i - 1 ;

        while(j >= 0 && ara[j] > item){
            ara[j+1] = ara[j] ;
            j--; 
        }

        ara[j+1] = item ;
        
        for(int k = 0 ; k < n ; k++){
            if(k > 0) printf(" ") ;
            printf("%d" ,ara[k]) ;
        } 
        printf("\n") ;
    }
        
    return 0 ;
}
