#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[100];

void printA() {
  for (int i=0; i<N; i++) {
    if (i > 0) putchar(' ');
    printf("%d", A[i]);
  }
  putchar('\n');
}

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) scanf("%d", &A[i]);
  int sc = 0;
  for (int i=0; i<N; i++) {
    int minI = i;
    for (int j=i; j<N; j++) {
      if (A[j] < A[minI]) minI = j;
    }
    if (i != minI) {
      swap(A[i], A[minI]);
      sc++;
    }
  }
  printA();
  printf("%d\n", sc);
  return 0;
}
