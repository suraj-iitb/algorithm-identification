#ifdef LOCAL_BUILD
#include "pch.h"
#define DLOG(msg) cout << "#" << __LINE__ << ":" << msg << endl;
#else
#include <bits/stdc++.h>
#define DLOG(msg)
#endif
using namespace std;

template <typename T>
void print(T& seq) {
  for (auto it = seq.begin(); it != seq.end(); ++it) {
    cout << *it;
    if (distance(it, seq.end()) != 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  list<int> seq;
  for (int t, i = 0; i < n; ++i) {
    cin >> t;
    seq.push_back(t);
  }

  print(seq);
  for (auto it = next(seq.begin()); it != seq.end();) {
    auto it2 = find_if(seq.begin(), it, [&](int v) { return v > *it; });
    seq.insert(it2, *it);
    it = seq.erase(it);
    print(seq);
  }
}
