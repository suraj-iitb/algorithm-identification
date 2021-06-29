#include <iostream>
using namespace std;
const int MAX = 1000;

void Print(int* A, int N) {
  for (int i = 0; i < N - 1; i++)
    cout << A[i] << " ";
  cout << A[N - 1] << endl;
}

void InsertionSort(int* A, int N) {
  for (int i = 1; i < N; i++) {
    Print(A, N);
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
  }
}

int main() {

  int N, A[MAX];
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];
  InsertionSort(A, N);
  Print(A, N);

  return 0;
}
