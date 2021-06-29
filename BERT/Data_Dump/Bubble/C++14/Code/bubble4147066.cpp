#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

void print_vec(vector<int> vec) {
  cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    if (i) {
      cout << ", ";
    }
    cout << vec.at(i);
  }
  cout << "]...size: " << vec.size() << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) { cin >> vec[i]; }

  bool flag = 1;
  int count = 0;

  while (flag) {
    flag = 0;

    for (int i = n - 1; i > 0; i--) {
      if (vec[i] < vec[i - 1]) {
        swap(vec[i], vec[i - 1]);
        count++;
        flag = 1;
      }
    }
  }

  rep(i, n) {
    if (i) {
      printf(" ");
    }
    printf("%d", vec[i]);
  }

  printf("\n%d\n", count);
}

