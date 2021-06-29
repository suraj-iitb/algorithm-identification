#include<stdio.h>

void selectionSort(int A[100], int n)
{
  int i, j, minj, swap;
  int cnt = 0;

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i!=minj){
      swap = A[i];
      A[i] = A[minj];
      A[minj] = swap;
      cnt++;
    }
  }
  printf("%d", A[0]);
  for(i=1; i<n; i++){
    printf(" %d", A[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

}


int main(){
  int i, N, A[100];

  scanf("%d", &N);

  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }

  selectionSort(A,N);
}
