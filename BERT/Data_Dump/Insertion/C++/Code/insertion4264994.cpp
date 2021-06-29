#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static const int n_max = 100;

void print_column(vector<int> a, int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  print_column(a, n);

  for (int i = 1; i < n; i++) {
    int v = a.at(i);
    int j = i - 1;
    for (j = i - 1; j >= 0; j--) {
      if (a.at(j) > v) {
        a.at(j + 1) = a.at(j);
      } else {
        break;
      }
    }
    a.at(j + 1) = v;
    print_column(a, n);
  }
  return 0;
}
