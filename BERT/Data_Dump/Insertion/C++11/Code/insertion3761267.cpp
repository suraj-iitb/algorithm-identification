#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BR "\n"
#define SP " "

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    ll temp = A[i];
    for (int j = 0; j < i; j++) {
      if (A[j] > temp) {
        for (int k = i; k > j; k--) {
          A[k] = A[k - 1];
        }
        A[j] = temp;
        break;
      }
    }
    for (int j = 0; j < N - 1; j++) {
      cout << A[j] << SP;
    }
    cout << A[N - 1] << BR;
  }
  return 0;
}
