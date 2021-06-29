#ifdef LOCAL_BUILD
#include "pch.h"
#define DLOG(msg) cout << "#" << __LINE__ << ":" << msg << endl;
#define DLOG_V(var) \
  cout << "#" << __LINE__ << ":" << #var << " : " << var << endl;
#else
#include <bits/stdc++.h>
#define DLOG(msg)
#define DLOG_V(var)
#endif
using namespace std;

template <typename Iter>
int merge(Iter begin, Iter mid, Iter end) {
  if (begin == mid || mid == end) {
    return 0;
  }
  vector<int> lbuf;
  vector<int> rbuf;
  copy(begin, mid, back_inserter(lbuf));
  copy(mid, end, back_inserter(rbuf));
  auto lit = lbuf.begin();
  auto rit = rbuf.begin();
  for (auto it = begin; it != end; ++it) {
    if (lit == lbuf.end() && rit == rbuf.end()) {
      throw std::logic_error("FAIL");
    }
    decltype(lit)* xit;
    if (lit == lbuf.end()) {
      xit = &rit;
    } else if (rit == rbuf.end()) {
      xit = &lit;
    } else {
      xit = (*lit > *rit) ? &rit : &lit;
    }
    *it = *(*xit);
    ++(*xit);
  }
  assert(lit == lbuf.end());
  assert(rit == rbuf.end());
  return distance(begin, end);
}

template <typename Iter>
int mergeSort(Iter begin, Iter end) {
  auto d = distance(begin, end) / 2;
  int count = 0;
  if (d > 0) {
    auto mid = next(begin, d);
    count += mergeSort(begin, mid);
    count += mergeSort(mid, end);
    count += merge(begin, mid, end);
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int t, i = 0; i < n; ++i) {
    cin >> t;
    nums.push_back(t);
  }
  auto count = mergeSort(nums.begin(), nums.end());
  bool first = true;
  for (auto&& num : nums) {
    if (!first) {
      cout << " ";
    }
    cout << num;
    first = false;
  }
  cout << endl << count << endl;
}
