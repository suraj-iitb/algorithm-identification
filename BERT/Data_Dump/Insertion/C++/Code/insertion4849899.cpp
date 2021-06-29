#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 入力
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // 出力
  for (int j = 0; j < n; j++) {
    cout << a[j] << (j==n-1 ? '\n' : ' ');
  }


  // 処理
  int x;
  int k;
  for (int i = 1; i < n; i++) {
    x = a[i];
    k = i;
    while (k > 0 && a[k - 1] > x) {
      a[k] = a[k - 1];
      k--;
    }
    a[k] = x;

    // 出力
    for (int j = 0; j < n; j++) {
      cout << a[j] << (j==n-1 ? '\n' : ' ');
    }
  }

  return 0;
}
