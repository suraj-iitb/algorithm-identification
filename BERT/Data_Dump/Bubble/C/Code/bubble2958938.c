#include<stdio.h>

int main(){
  int i,j,n;
  int temp,A[100],ch=0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = n-1 ; i > 0 ; i--){
    for(j = n-1 ; j > 0 ; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	ch++;
      }
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
  printf("%d\n",ch);
  
  return 0;
}

