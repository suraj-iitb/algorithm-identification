#include<stdio.h>

int main()
{
  int i, j, n, temp, flag, A[100];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  flag = 1;
  j = 0;
  while(flag){
    flag = 0;
    for(i = n-1; i >= 1; i--){
      if(A[i] < A[i-1]){
	temp = A[i-1];
	A[i-1] = A[i];
	A[i] = temp;
	flag = 1;
	j++;
      }
    }
  }
  
  for(i = 0; i < n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);

  printf("%d\n", j);
  
  return 0;
}
