#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  int change_cnt = 0;
  for(int i = 0; i < n; i++) {
    int minj = i;
    for(int j = i; j < n; j++) {
      if(a[j] < a[minj]) {
        minj = j;
      }
    }
    if(minj != i) {
      int tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      change_cnt++;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << a[i];
    if(i != n-1) cout << " ";
    else cout << endl;
  }
  cout << change_cnt << endl;
  return 0;
}

