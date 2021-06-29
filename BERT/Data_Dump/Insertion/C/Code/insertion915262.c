#include<stdio.h>
#define N 100

int main(){
  int i, j, k, key, n, A[N];
  scanf("%d", &n);
  for(i = 0; i < n ; i++)scanf("%d", &A[i]);
  for(i = 1; i <= n; i++){
    key = A[i];
    j = i - 1;
    for(k=0; k < n; k++){
      printf("%d", A[k]);
      if(k < n-1)printf(" ");
    }
    printf("\n");
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
  }
  return 0;
}
