#include <bits/stdc++.h>

using namespace std;

int N;
int a[100];

void solve() {
  int swap_cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N-1; j > i; j--) {
      if(a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
        swap_cnt++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << a[i] << (i == N-1 ? "\n" : " ");
  }
  cout << swap_cnt << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  solve();
}

