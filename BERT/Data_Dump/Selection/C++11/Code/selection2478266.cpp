#include <iostream>
#include <vector>
using namespace std;

void myprint(vector<int> &a) {
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (it != a.begin()) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;

  vector<int> a;
  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    a.push_back(t);
  }

  int counter = 0;
  for (int i = 0; i < N; ++i) {
    int m = i;
    for (int j = i; j < N; ++j) {
      if (a[j] < a[m]) {
        m = j;
      }
    }
    if (i != m) {
      int t = a[i];
      a[i] = a[m];
      a[m] = t;
      ++counter;
    }
  }

  myprint(a);
  cout << counter << endl;

  return 0;
}
