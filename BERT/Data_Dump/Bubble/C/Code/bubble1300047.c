#include<stdio.h>
#define N 100
main(){
  int j, i, n, flag, A[N], count;
  
  scanf("%d", &n);
  
  for(i = 0; i <= n - 1; i++){
    scanf("%d", &A[i]);
  }
  
  count = 0;
  
  for(i = 0; i < n; i++){
    for(j = n - 1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
	flag = A[j];
	A[j] = A[j-1];
      A[j-1] = flag;
      count++;
      }
    }
  }
  
  for(i =0; i <= j; i++){
    printf("%d",A[i]);
    if(i < j)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
