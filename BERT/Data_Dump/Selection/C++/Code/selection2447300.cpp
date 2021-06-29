#include<cstdio>
#include<algorithm>
using namespace std;


void trace(int A[], int N){
  int i;
  for (i=0; i<N; i++){
    if (i>0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int selectionSort(int A[], int N){
  int i, j, sw = 0, minj;
  for (i=0; i<N-1; i++){
    minj = i;
    for (j=i; j<N; j++){
      if (A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if (i != minj) sw++;
  }
  return sw;
}

int main() {
  int N, i, ans;
  int A[100];

  scanf("%d", &N);
  for (i=0; i<N; i++) scanf("%d", &A[i]);

  // trace(A, N);
  ans = selectionSort(A, N);
  trace(A, N);

  printf("%d\n", ans);

  return 0;
}
