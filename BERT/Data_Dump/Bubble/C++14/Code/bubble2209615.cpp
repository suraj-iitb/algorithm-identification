#ifdef LOCAL_BUILD
#include "pch.h"
#define DLOG(msg) cout << "#" << __LINE__ << ":" << msg << endl;
#else
#include <bits/stdc++.h>
#define DLOG(msg)
#endif
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int t, i = 0; i < n; ++i) {
    cin >> t;
    nums.push_back(t);
  }
  int count = 0;
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    for (auto it2 = nums.rbegin(); distance(it2, make_reverse_iterator(it)) >= 2; ++it2) {
      auto next_ = next(it2);
      if (*it2 < *next_) {
        iter_swap(it2, next_);
        ++count;
      }
    }
  }

  for (auto it = nums.begin(); it != nums.end(); ++it) {
    cout << *it;
    if (next(it) != nums.end()) {
      cout << " ";
    }
  }
  cout << endl;
  cout << count << endl;
}
