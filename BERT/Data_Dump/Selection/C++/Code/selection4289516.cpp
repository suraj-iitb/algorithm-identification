#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int selectionSort(vector<int> &a, int n) {
  int sw = 0;
  for (int i = 0; i < n - 1; i++) {
    int minj = i;

    for (int j = i + 1; j < n; j++) {
      if (a.at(minj) > a.at(j)) {
        minj = j;
      }
    }
    swap(a.at(minj), a.at(i));
    if (i != minj) sw++;
  }
  return sw;
}

int main() {
  int n, sw;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);

  sw = selectionSort(a, n);

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
