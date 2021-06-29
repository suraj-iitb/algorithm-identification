#include <bits/stdc++.h>
using namespace std;

int selection(vector<int> &v) {
  int n = 0;
  for (int i = 0; i < v.size(); i++) {
    int mini = i;
    for (int j = i; j < v.size(); j++) {
      if (v[j] < v[mini]) {
        mini = j;
      }
    }
    if (i != mini) {
      swap(v[i], v[mini]);
      n++;
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
  int num = selection(v);
  for (int i = 0; i < N; i++) {
    cout << v.at(i);
    if (i != N-1) cout << " ";
  }
  cout << endl;
  cout << num << endl;
}
