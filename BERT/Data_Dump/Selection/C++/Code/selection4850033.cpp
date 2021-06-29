#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Input
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // Process
  int idxMin, tmp;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    idxMin = i;
    for (int j = i+1; j < n; j++) {
      if (a[j] < a[idxMin]) {
        idxMin = j;
      }
    }
    if (i != idxMin) {
      tmp = a[i];
      a[i] = a[idxMin];
      a[idxMin] = tmp;
      cnt++;
    }
  }
  // Output
  for (int i = 0; i < n; i++) {
    cout << a[i] << (i==n-1 ? '\n' : ' ');
  }
  cout << cnt << endl;

  return 0;
}
