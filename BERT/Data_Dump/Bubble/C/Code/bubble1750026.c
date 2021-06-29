#include <stdio.h>

int N = 100;
int count = 0;

void BubbleSort(int A[], int n){

  int k, l, tmp;

  for(k = 0; k <= n-1; k++){
    for(l = n-1; l >= k+1; l--){
      if(A[l] < A[l-1]){
        tmp = A[l];
        A[l] = A[l-1];
        A[l-1] = tmp;
        count++;
      }
    }
  }
}

int main(){

  int i, j, n;
  int A[N+1];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  BubbleSort(A, n);

  for(j = 1; j <= n; j++){
    if(j > 1){printf(" ");
  }
    printf("%d", A[j-1]);
  }

  printf("\n");
  printf("%d\n", count);

  return 0;
}
