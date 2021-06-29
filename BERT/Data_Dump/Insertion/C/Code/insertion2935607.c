#include<stdio.h>
#define N 100
int main(){
  int i,j,v,n;
  int A[1000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){  
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<n;i++){
    for(j=0;j<n;j++){
      if(j==n-1){
	printf("%d\n",A[j]);
	break;
      }
      printf("%d ",A[j]);
    } 
    v = A[i];   
    j = i -1;
    while((j >= 0 )&&( A[j] > v)){
      A[j+1] =A[j];
      j--;
    }
  
    A[j+1]= v;
  }
  for(i=0;i<n;i++){
      if(i==n-1){
	printf("%d\n",A[i]);
	break;
      }
 printf("%d ",A[i]);      
    }
  return 0;
}

