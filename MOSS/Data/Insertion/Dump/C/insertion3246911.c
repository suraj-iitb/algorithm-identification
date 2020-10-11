#include "stdio.h"
 
 
int main()
{
      int n, i,j,k;
      int A[1000];
      int B;
 
      scanf("%d", &n);
 
      for (i = 0;i < n;i++) {
         scanf("%d", &A[i]);
                          }     
       for(j=0;j<n-1;j++){
                  printf("%d ",A[j]);
              }
             
              printf("%d\n",A[n-1]);   

      for (i = 1;i < n;i++) {
            for(int j=i;j!=0 && A[j]<A[j-1];--j){
              B = A[j-1];
              A[j-1]=A[j];
              A[j]= B;  
            }    
            for(k=0;k<n-1;k++){
                  printf("%d ",A[k]);
              }
              printf("%d\n",A[n-1]); 
                         
              
       }       

 
             
 
    return 0;
}
