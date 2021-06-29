#include <bits/stdc++.h>
using namespace std;

void print_sort(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      printf("%d\n", A[i]);
    } else {
      printf("%d ", A[i]);
    }
  }
}

void insertion_sort(int A[], int N) {
  print_sort(A, N);

  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    print_sort(A, N);
  }
}

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  insertion_sort(A, N);
}
