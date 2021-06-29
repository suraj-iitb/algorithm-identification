#include <iostream>
using namespace std;

void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}

int x[200];

int main() {
  int ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j >= i + 1; j--) {
      if (x[j - 1] > x[j]) {
        swap(x[j - 1], x[j]);
        ans++;
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << x[i] << " ";
  }
  cout << x[n - 1] << endl;
  cout << ans << endl;
  return 0;
}
