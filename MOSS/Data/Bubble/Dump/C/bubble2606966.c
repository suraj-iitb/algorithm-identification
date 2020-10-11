#include <stdio.h>
 
int main(){
 
  int i,j,tmp,n,A[100];
 
  int count=0;
  
   scanf("%d",&n);

  if(n<1||n>100)

   return 0;
  
 for(i=0;i<n;i++){
  
   scanf("%d",&A[i]);
 
  }
  
 for(i=0;i<n;i++){
  
   for(j=1;j<n;j++){
     
     if(A[j]<A[j-1]){
      
        tmp=A[j];
       
        A[j]=A[j-1];
       
        A[j-1]=tmp;
      
         count++;
    
       }
   
     }

  }
 
 for(i=0;i<n;i++){
   
     printf("%d",A[i]);
  
    if(i<n-1)
      
     printf(" ");
   
    if(i==n-1)
  
     printf("\n");
 
  }

   printf("%d\n",count);

    return 0;

 }
