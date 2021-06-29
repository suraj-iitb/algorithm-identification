#include <iostream>
using namespace std;
const int MAX = 100;

void Print(int* A, int N) {
  for (int i = 0; i < N - 1; i++)
    cout << A[i] << " ";
  cout << A[N - 1] << endl;
}

int BubbleSort(int* A, int N) {
  int flag = 1;
  int num_swap = 0;
  while (flag) {
    flag = 0;
    for (int j = N - 1; j >= 1; j--) {
      if (A[j] < A[j - 1]) {
        int v = A[j];
        A[j] = A[j - 1];
        A[j - 1] = v;
        flag = 1;
        num_swap++;
      }
    }
  }
  return num_swap;
}

int main() {
  int N, A[MAX];
  cin >> N;
  for (int i = 0 ; i < N; i++)
    cin >> A[i];

  int num_swap = BubbleSort(A, N);
  Print(A, N);
  cout << num_swap << endl;

  return 0;
}
