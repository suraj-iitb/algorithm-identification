#include <stdio.h>

int main(){

  int n,i,j,count = 0,minj,v;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=n-1;i++){
    minj = i;
    for(j=i;j<=n-1;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i!=minj){
      v = A[i];
      A[i] =  A[minj];
      A[minj] = v;
      count++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }

    else{
      printf("\n");
    }
    
  }

  printf("%d\n",count);
  return 0;
}

