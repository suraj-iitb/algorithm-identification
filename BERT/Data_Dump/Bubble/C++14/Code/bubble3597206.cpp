#include <bits/stdc++.h>
using namespace std;

void print_row(vector<int> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A.at(i);
    if (i < A.size() - 1) {
      cout << " ";
    }
    else {
      cout << endl;
    }
  }
}

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
  int flag = 1;
  while (flag == 1) {
    flag = 0;
    for (int j = N-1; j > 0; j--) {
      if (A.at(j-1) > A.at(j)) {
        int temp = A.at(j-1);
        A.at(j-1) = A.at(j);
        A.at(j) = temp;
        flag = 1;
        cnt++;
      }
    }
  }
  
  // Output
  print_row(A);
  cout << cnt << endl;
}
