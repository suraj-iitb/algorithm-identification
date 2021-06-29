#include<stdio.h>
#define N 1000

int main(){
  int i, j, k, temp, n, A[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i == (n-1)) break;
    printf(" ");
  }
  printf("\n");

  for(i = 1; i < n; i++){
    temp = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > temp){
      A[j+1] = A[j];
      j = j - 1;
    }
    A[j+1] = temp;
    for(k = 0; k < n; k++){
      printf("%d", A[k]);
      if(k == (n-1))break;
      printf(" ");
    }
    printf("\n");
  }

  return 0;
}
