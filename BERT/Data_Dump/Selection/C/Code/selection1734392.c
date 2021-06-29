#include<stdio.h>

int main()
{
  int n, i, j, temp, min, count=0, A[100];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i <= n-1; i++){
    min = i;
    for(j = i; j <= n-1; j++){
      if(A[j] < A[min]){
	min = j;
      }
    }
    if(A[min] < A[i]){
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
      count++;
    }
  }
  
  for(i = 0; i < n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);

  printf("%d\n", count);
  
  return 0;
}
