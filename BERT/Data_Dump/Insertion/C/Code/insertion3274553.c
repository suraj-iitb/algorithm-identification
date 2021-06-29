#include<stdio.h>
int main(){
  int A[100],i,j,v,N,x;
  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  for(i = 0;i < N;i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  for(i = 1;i < N;i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(x = 0;x < N;x++){
      if(x > 0) printf(" ");
      printf("%d",A[x]);
    }
    printf("\n");
  }
  return 0;
}

