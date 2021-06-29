#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  int C = 0;
  cin >> N;

  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  bool f;
  f = true;
  while (f) {
    f = false;
    for (int j = N - 1; j > 0; j--) {
      if (vec.at(j) < vec.at(j - 1)) {
        int t = vec.at(j);
        vec.at(j) = vec.at(j - 1);
        vec.at(j - 1) = t;
        f = true;
        C++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << vec.at(i);
  }

  cout << endl <<  C << endl;
}

