#include <stdio.h>

int selectionsort(int A[100], int N);

int main(){
  int A[100], N, i, x;
  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &A[i]);
  x=selectionsort(A,N);
  for(i=0;i<N-1;i++) printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
  printf("%d\n", x);
  return 0;
}

int selectionsort(int A[100], int N){
  int i, j, k, minj, count=0, v;
  for(i=0;i<=N-2;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])minj=j;
    }
    if(A[i]!=A[minj]){
      v=A[i];
      A[i]=A[minj];
      A[minj]=v;
      count++;
    }
  }
  return count;
}


