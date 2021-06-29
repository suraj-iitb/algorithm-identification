#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N) {
  for (int i=0; i<N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}

void insertion(vector<int> A, int N) {
  int key;
  for (int i=1; i<N; i++) {
    key = A.at(i);
    int j = i-1;
    while (j>=0 && key < A.at(j)) {
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = key;
    trace(A, N);
  }
}


int main() {
  int N, key;
  vector<int> A(N);

  // read inputs
  cin >> N;
  for (int i=0; i<N; i++) cin >> A.at(i);

  // sort & output
  trace(A, N);
  insertion(A, N);

}

