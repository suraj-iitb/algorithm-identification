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

  vector<vector<int>> ans;
  ans.push_back(vec);

  for (int i = 1; i < n; i++) {
    int v = vec[i];
    int j = i - 1;

    while (j >= 0 && vec[j] > v) {
      vec[j + 1] = vec[j];
      j--;
    }

    vec[j + 1] = v;
    ans.push_back(vec);
  }

  for (auto &&i : ans) {
    rep(j, n) {
      if (j) {
        printf(" ");
      }
      printf("%d", i[j]);
    }
    printf("\n");
  }
}

