#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[100];

void printA() {
  for (int i=0; i<N; i++) {
    printf("%d", A[i]);
    if (i < N-1) putchar(' ');
  }
  putchar('\n');
}

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) scanf("%d", &A[i]);
  for (int i=1; i<N; i++) {
    printA();
    int key = A[i], j = i-1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
  printA();
  return 0;
}
