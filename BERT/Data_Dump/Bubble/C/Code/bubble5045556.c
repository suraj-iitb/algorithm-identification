#include <stdio.h>
int bubbleSort(int *, int);
int main(){
  int N, i, count;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  count = bubbleSort(A, N);
  for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i < N - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}
int bubbleSort(int A[], int n){
  int flag = 0, i, j, k;
  for(i = 0; i < n; i++){
    for(j = n - 1; i < j; j--){
      if(A[j] < A[j - 1]){
        k = A[j];
        A[j] = A[j - 1];
        A[j - 1] = k;
        flag++;
      }
    }
  }
  return flag;
}

