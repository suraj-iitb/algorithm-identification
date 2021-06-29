#include <stdio.h>

int main(){
  int i, j, mini, N, A[1000], n, swap=0;
  
  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }
  
  for(i=0;i<N;i++){
    mini = i;
    for(j=i;j<N;j++){
      if(A[j] < A[mini]) mini = j;
    }
    if(mini != i){
    n = A[i];
    A[i] = A[mini];
    A[mini] = n;
    swap++;
    }
  }
  
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", swap);
  
  return 0;
}
