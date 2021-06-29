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
  vector<int> v(n);
  rep(i, n) { cin >> v[i]; }
  int count = 0;

  rep(i, n) {
    int minj = i;

    for (int j = i; j < n; j++) {
      if (v[j] < v[minj]) {
        minj = j;
      }
    }

    if (i != minj) {
      count++;
    }

    swap(v[i], v[minj]);
  }

  rep(i, n) {
    if (i) {
      printf(" ");
    }
    printf("%d", v[i]);
  }

  printf("\n%d\n", count);
}

