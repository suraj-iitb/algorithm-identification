#include <stdio.h>
#define N 100

main(){
  int i, j, n, c=0, key=0, A[N], mini=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  if(n != 1){
    for(i = 0; i < n; i++){
      mini = i;
      for(j = i; j < n; j++){
	if(A[j] < A[mini]) mini = j;
      }
      if(mini != i){
      key = A[i];
      A[i] = A[mini];
      A[mini] = key;
      c++;
      }
    }
  }
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}
