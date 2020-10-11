#include<stdio.h>

int main(){
  int i, j, n, min, v, count = 0;
  int A[100];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(A[j] < A[min]) min = j;
    }

    if(i != min){
      v = A[i];
      A[i] = A[min];
      A[min] = v;
      count++;
    }
    printf("%d",A[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
