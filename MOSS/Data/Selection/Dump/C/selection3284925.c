#include<stdio.h>

#define N 100

int main(){
  int a,i,j,count = 0;
  int A[N+1];
  int k,l;

  scanf("%d",&a);

  for(i = 1;i <= a;i++){
    scanf("%d",&A[i]);
  } 
    for (i = 1;i <= a;i++){
      k = i;
      for(j = i;j <= a;j++){
	if(A[j] < A[k]){
	  k = j;
	  }
      }
      l = A[i];
      A[i] = A[k];
      A[k] = l;
      if(k != i){
      count++;
      }
    }
    
  for(i = 1;i <= a;i++){
    if(i == a){
      printf("%d",A[i]);
    }
    else
    printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}


