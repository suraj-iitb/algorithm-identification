#include<stdio.h>
 
int main(){
  int A[100];
  int i,j,n,temp,m;
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
   
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
    temp=A[j];
    A[j]=A[j-1];
    A[j-1]=temp;
    m = m + 1;
      }
    }
  }
 
   for(i=0;i<n-1;i++){
     printf("%d ",A[i]);
 
    
    }
 
   printf("%d\n",A[i]);
  printf("%d\n",m);
 
 
  return 0;
}
