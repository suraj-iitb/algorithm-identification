#include<stdio.h>
#define N 100

int main(){
  
int n,i,j,A[N],min,b;

int c=0;
 
  scanf("%d",&n);
  
   for(i = 0; i < n; i++){
    
   scanf("%d",&A[i]);
  
 }
  
  for(i = 0; i < n; i++){
    
      min = i;
   
  for(j = i; j < n; j++){
      
      if(A[j] < A[min]){
   
        min = j;
      
    }
    
 }
   
      if(min != i){
    
      b = A[i];
    
      A[i] = A[min];
    
      A[min] = b;
    
        c++;
    
      }
 
  }
 
  for(i = 0; i < n-1; i++){
    
      printf("%d ",A[i]);
  
  }                              

      printf("%d\n",A[n-1]);

      printf("%d\n",c);
 
        return 0;

}
