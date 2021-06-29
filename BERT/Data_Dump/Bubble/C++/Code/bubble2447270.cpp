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

int bubbleSort(int A[], int N){
  int sw = 0;
  bool flag = true;
  for (int i=0; flag; i++){
    flag = false;
    for (int j=N-1; j>i; j--){
      if (A[j] < A[j-1]){
        swap(A[j], A[j-1]);
        flag = true;
        sw ++;
      }
    }
  }
  return sw;

}

int main() {
  int N, i, ans;
  int A[100];

  scanf("%d", &N);
  for (i=0; i<N; i++) scanf("%d", &A[i]);

  // trace(A, N);
  ans = bubbleSort(A, N);
  trace(A, N);

  printf("%d\n", ans);

  return 0;
}
