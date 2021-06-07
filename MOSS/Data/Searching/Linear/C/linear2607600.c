
#include<stdio.h>
  
  
int main(void){
 
int i,j,N,v,S[10000],T[10000],q; 
int c =0;
  
    scanf("%d", &N);
     for ( i = 0; i < N; i++ ){ 
scanf("%d", &S[i]);
}
   
 scanf("%d", &q);
     for ( i = 0; i < q; i++ ){ 
scanf("%d", &T[i]);
}
  
 
for(i=0;i<q;i++){
    
        for ( j = 0 ; j <N; j++ ) {
            if ( T[i] == S[j] ) {
                 
      
                 
c++;
break;
            }
        }
    }
  
     
 
  
    printf("%d\n",c);
  
    return 0;
}
