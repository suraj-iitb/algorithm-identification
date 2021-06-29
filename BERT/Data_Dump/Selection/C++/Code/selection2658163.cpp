#include <iostream>
using namespace std;
const int MAX = 100;

void Print(int* A, int N) {
  for (int i = 0; i < N - 1; i++)
    cout << A[i] << " ";
  cout << A[N - 1] << endl;
}

int SelectionSort(int* A, int N) {
  int num_swap = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj])
        minj = j;
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      num_swap++;
    }
  }
  return num_swap;
}

int main() {
  int N, A[MAX];
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int num_swap = SelectionSort(A, N);
  Print(A, N);
  cout << num_swap << endl;

  return 0;
}
