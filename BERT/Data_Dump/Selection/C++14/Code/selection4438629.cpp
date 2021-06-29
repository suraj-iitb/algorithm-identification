#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> A(n);
  for (auto& item : A) {
    cin >> item;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (A[minj] > A[j]) minj = j;
    }
    if (i < minj) {
      swap(A[i], A[minj]);
      ++cnt;
    }
  }

  const char* sep = "";
  for (auto& item : A) {
    cout << sep << item;
    sep = " ";
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

