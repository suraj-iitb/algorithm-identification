#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> &a, int n) {
  int sw = 0;
  int flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = n - 1; j > i; j--) {
      if (a.at(j - 1) > a.at(j)) {
        swap(a.at(j - 1), a.at(j));
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int n, sw;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);

  sw = bubbleSort(a, n);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a.at(i);
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
