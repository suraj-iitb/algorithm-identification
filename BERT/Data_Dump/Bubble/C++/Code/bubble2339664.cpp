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
    bool loop = false;
    for (int j=N-1; j>i; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        sc++;
        loop = true;
      }
    }
    if (!loop) break;
  }
  printA();
  printf("%d\n", sc);
  return 0;
}
