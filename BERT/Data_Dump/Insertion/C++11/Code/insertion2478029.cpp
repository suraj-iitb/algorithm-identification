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

  myprint(a);
  for (int i = 1; i < N; ++i) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = v;
    myprint(a);
  }

  return 0;
}
