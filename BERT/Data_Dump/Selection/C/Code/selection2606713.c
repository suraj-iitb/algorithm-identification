#include<stdio.h>


int main(void){
 
int i,j,N,minj,v,a[10000]; 
int c =0;

    scanf("%d", &N);
     for ( i = 0; i < N; i++ ){ 
scanf("%d", &a[i]);
}
 
 
for(i=0;i<N;i++){
minj=i;
for(j=i;j<N;j++){

            if ( a[j] < a[minj] ) {
      minj=j;
}
}
if(i!=minj){
               v = a[i];
                a[i] = a[minj];
                a[minj] = v;
                
               
c++;
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
