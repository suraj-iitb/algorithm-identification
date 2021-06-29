#include<stdio.h>

int main(){
  int n, i, j, key, k;
  scanf("%d", &n);
  int A[n];
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  for(k = 0 ; k < n ; k++){
    if(k == n - 1)printf("%d", A[k]);
    else printf("%d ", A[k]);
  }
  printf("\n");
  for(i = 1 ; i < n ; i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
    for(k = 0 ; k < n ; k++){
      if(k == n - 1)printf("%d", A[k]);
      else printf("%d ", A[k]);
    }
    printf("\n");
  }
  return 0;
}

