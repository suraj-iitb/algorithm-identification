#include <bits/stdc++.h>

using namespace std;

int N;
int a[100];

void solve() {
  int swap_cnt = 0;

  for (int i = 0; i < N; i++) {
    int mini = i;
    for (int j = i; j < N; j++) {
      if(a[j] < a[mini]) {
        mini = j;
      }
    }
    if(mini != i) {
      swap_cnt++;
      swap(a[i],a[mini]);
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

