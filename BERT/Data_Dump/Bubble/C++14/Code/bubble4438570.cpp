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

  bool flag;
  int cnt = 0;
  do {
    flag = false;
    for (int i = n - 1; 0 < i; --i) {
      if (A[i - 1] > A[i]) {
        swap(A[i - 1], A[i]);
        flag = true;
        ++cnt;
      }
    }
  } while (flag);

  const char* sep = "";
  for (auto& item : A) {
    cout << sep << item;
    sep = " ";
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

