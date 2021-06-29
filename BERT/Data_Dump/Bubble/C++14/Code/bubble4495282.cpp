#include <bits/stdc++.h>
using namespace std;
int a[100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int flag = 1, cnt = 0;
  while (flag) {
    flag = 0;
    int i = 0;
    for (int j = n - 1; j >= i + 1; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = 1;
        cnt++;
      }
    }
    i++;
  }
  for (int i = 0; i < n; i++) {
    cout << (i ? " " : "") << a[i];
  }
  cout << "\n" << cnt << "\n";
}
