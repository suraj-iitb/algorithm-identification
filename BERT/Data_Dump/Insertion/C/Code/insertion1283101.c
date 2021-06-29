#include<stdio.h>
int main(){
  int i, j, k, n, v;
  int A[100];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  /* Insertion Sort */
  for(i = 1; i <= n; i++){
    v = A[i];
    j = i - 1;
    for(k = 0; k < n; k++){
      printf("%d",A[k]);
      if(k != n - 1) printf(" ");
    }
    printf("\n");
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
  }

  return 0;
}
