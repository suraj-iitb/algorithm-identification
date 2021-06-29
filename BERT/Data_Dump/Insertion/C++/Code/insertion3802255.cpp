#include<iostream>

using namespace std;

void trace(int N, int A[]) {
  cout << A[0];

  for (int i = 1; i < N; i++) cout << " " << A[i];

  cout << endl;
}

int main() {
  int N, A[1000], v;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  trace(N, A);

  for ( int i = 1; i < N; i++) {
    v = A[i];

    int j = 0;
    for ( ; j < i; j++ ) {
      if (A[i] < A[j]) {
        for (int k = i; k > j; k--) {
            A[k] = A[k-1];
        }

        A[j] = v;
        break;
      }
    }

    trace(N, A);
  }
}

