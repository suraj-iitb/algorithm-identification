#include<stdio.h>

int main(){
  int i,j,v,n;
  int A[100];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

 
  for(i = 0 ; i < n ; i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(j = 0 ; j < n ; j++){
      if(j != n-1){
	printf("%d ",A[j]);
      }
      else if(j == n-1){
	printf("%d",A[j]);
      }

    }
    
    printf("\n");
  }

  return 0;
}

