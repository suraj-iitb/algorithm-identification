#include <iostream>

using namespace std;

int cnt;

void swap(int i, int j, int *A);

void selectionSort(int *A, int N) {
  int minj, j, i;
  
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) {
	minj = j;
      }
    }
    if (i != minj) {
      cnt++;
    }
    swap(i, minj, A);
  }
}

void swap(int i, int j, int *A) {
  int tmp;

  //cnt++;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

int main() {
  cnt = 0;
  int N, A[100];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  selectionSort(A, N);
  
  for (int i = 0; i < N - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[N - 1] << endl;
  cout << cnt << endl;

  return 0;
}
  
  
