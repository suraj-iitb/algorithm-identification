#include <stdio.h>

int bubbleSort(int A[], int N){
  int cnt = 0, v, i, j, flag = 1;

  for(i=0;flag;i++){
    flag = 0;
    for(j=N-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
        v = A[j-1];
        A[j-1] = A[j];
        A[j] = v;
        flag = 1;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int N, A[100], cnt, i;

  scanf("%d", &N);

  for(i=0;i<N;i++) scanf("%d", &A[i]);

  cnt = bubbleSort(A, N);

  for(i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", cnt);

  return 0;
}
