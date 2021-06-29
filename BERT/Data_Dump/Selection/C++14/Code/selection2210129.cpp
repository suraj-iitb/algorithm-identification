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
    auto it2 = min_element(it, nums.end());
    iter_swap(it, it2);
    if (it != it2) {
      ++count;
    }
  }
  for (auto&& num : nums) {
    cout << num;
    if (&num != &nums.back()) {
      cout << " ";
    }
  }
  cout << endl << count << endl;
}
