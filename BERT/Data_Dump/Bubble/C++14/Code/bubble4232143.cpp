#include <bits/stdc++.h>
using namespace std;

int bubble(vector<int> &v) {
  int n = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = v.size() - 1; j > i; j--) {
      if (v[j] < v[j - 1]) {
        swap(v[j], v[j-1]);
        n++;
      }
    }
  }
  return n;
}

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }
  int num = bubble(v);
  for (int i = 0; i < N; i++) {
    cout << v.at(i);
    if (i != N-1) cout << " ";
  }
  cout << endl;
  cout << num << endl;
}
