#include <iostream>

using namespace std;

#define MAX 100
#define MIN 1

int selection_sort(int A[MAX], int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      count++;
    }
  }

  return count;
}

int main() {
  int N;
  cin >> N;
  int A[MAX] = { 0 };
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int count = selection_sort(A, N);

  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;

  cout << count << endl;

  return 0;
}
