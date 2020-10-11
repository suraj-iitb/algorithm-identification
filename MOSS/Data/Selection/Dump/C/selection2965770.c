#include<stdio.h>

int main(){
  int i,j,n,k;
  int temp,A[100],minj,count=0;
  
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0 ; i < n-1 ; i++){
    minj = i;
    for(j = i+1 ; j < n ; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(minj != i){
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count++;
    }
  }
  
  for(j = 0 ; j < n ; j++){
    if(j != n-1){
      printf("%d ",A[j]);
    }
    else if(j == n-1){
      printf("%d\n",A[j]);
    }
  }
  printf("%d\n",count);

  return 0;
}



  

