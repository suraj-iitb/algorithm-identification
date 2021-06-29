#include <stdio.h>

int main(){
  int arr,A[100],i,j=0,k,v;
  
  scanf("%d",&arr);
  for(i=1;i<=arr;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<=arr;i++){
    v = A[i];
    j = i-1;
    
    while(j > 0 && A[j] > v)
      {
	A[j+1] = A[j];
	j--;
      }
    
    A[j+1] = v;
    for(k=1;k<=arr;k++){
      if(k == arr)
	printf("%d\n",A[k]);
      else
	printf("%d ",A[k]);
    } 
  }
  
  return 0;
}
