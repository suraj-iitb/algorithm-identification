#include<stdio.h>

int main(){
  int i, j, n, v, count = 0;
  int A[100];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);

  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if(A[j - 1] > A[j]){
        v = A[j];
        A[j] = A[j - 1];
        A[j - 1] = v;
        count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
