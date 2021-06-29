#include<stdio.h>
#define N 100

main(){
  int count = 0, i, j, k, l, mini, A[N];
  scanf("%d", &k);
  for(i = 0;i < k;i++){
    scanf("%d", &A[i]);
  }
  for(i = 0;i < k;i++){
    mini = i;
    for(j = i;j < k;j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
    if(mini != i){
      l = A[i];
      A[i] = A[mini];
      A[mini] = l;
      count++;
    }    
  }
  for(i = 0;i < k-1;i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[k-1], count);
  return 0;
}
