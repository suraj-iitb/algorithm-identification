#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i != a.size() - 1) cout << " ";
  }
  cout << "\n";
  for (int i = 1; i <= a.size() - 1; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  insertion_sort(v);
}

