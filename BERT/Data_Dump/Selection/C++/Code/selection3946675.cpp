#include<iostream>
#include<vector>
using namespace std;

int selectionSort(vector<int> &A) {
  int sw = 0;
  int N = A.size();
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i + 1; j < N; j++) {
      if (A.at(j) < A.at(minj)) {
        minj = j;
      }
    }
    if (A.at(i) > A.at(minj)) {
      swap(A.at(i), A.at(minj));
      sw++;
    }
  }
  return sw;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  int sw = selectionSort(A);

  for (int i = 0; i < N; i++) {
    cout << A.at(i);
    if (i < N - 1) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }

  cout << sw << endl;
}
