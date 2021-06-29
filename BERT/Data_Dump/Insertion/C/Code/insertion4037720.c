#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,k,v,N,A[100];

  scanf("%d",&N);
  if(N < 1 || N > 100) exit(1);

  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 1000) exit(2);
  }

  for(i = 1;i < N;i++){
    
    for(k = 0;k < N;k++){
    if(k == 0) printf("%d",A[k]);
    else printf(" %d",A[k]);
  }
    printf("\n");
    
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }

  for(i = 0;i < N;i++){
    if(i == 0) printf("%d",A[i]);
    else printf(" %d",A[i]);
  }

  printf("\n");
  return 0;
}

