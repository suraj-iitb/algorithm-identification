#include <bits/stdc++.h>
using namespace std;

int main() {
  // Input
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  // Compute
  int cnt = 0;
  int min_j;
  for (int i = 0; i < N; i++) {
    min_j = i;
    for (int j = i; j < N; j++) {
      if (A.at(min_j) > A.at(j)) {
        min_j = j;
      }
    }
    int temp = A.at(i);
    A.at(i) = A.at(min_j);
    A.at(min_j) = temp;
    if (min_j != i) {
      cnt++;
    }
  }
  
  // Output
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << A.at(i);
  }
  cout << endl;
  cout << cnt << endl;
}
