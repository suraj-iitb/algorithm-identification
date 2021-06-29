#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& A) {
  cout << A[0];
  for (int i = 1; i < A.size(); i++) {
    cout << ' ' << A[i];
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  print(A);
  for (int i = 1; i < N; i++) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 and A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    print(A);
  }
}
