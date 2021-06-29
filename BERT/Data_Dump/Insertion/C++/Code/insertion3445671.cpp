#include <bits/stdc++.h>

using namespace std;

int N;
int A[100];

void show() {
  for (int i = 0; i < N; i++) {
    cout << A[i] << (i == N-1 ? "\n" : " ");
  }
}

void solve() {
  show();
  for (int i = 1; i < N; i++) {
    int key = A[i];
    int j = i-1;
    while(j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    show();
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  solve();
}

