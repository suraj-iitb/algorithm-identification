#include<stdio.h>
 
 
int main(void){
 int flag = 1;
int i,j,N,v,a[10000]; 
int c =0;
 
    scanf("%d", &N);
     for ( i = 0; i < N; i++ ){ 
scanf("%d", &a[i]);
}
  
 while ( flag ) {
        flag = 0;
        for ( j = N - 1; j >0; j-- ) {
            if ( a[j] < a[j - 1] ) {
                v = a[j];
                a[j] = a[j - 1];
                a[j - 1] = v;
                 
                flag = 1;
c++;
            }
        }
    }
 
    
    for ( i = 0; i < N; i++ ) {
if(i>0){
printf(" ");
}
 
        printf("%d", a[i]);
}
printf("\n");
   
     
 
    printf("%d\n",c);
 
    return 0;
}
