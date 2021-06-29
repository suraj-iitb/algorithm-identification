#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX;
int CNT = 0;
void merge(vector<int> &S, int left, int mid, int right) {
  int nl = mid - left, nr = right - mid;
  vector<int> L(nl + 1), R(nr + 1);
  for (size_t i = 0; i < nl; i++) {
    L.at(i) = S.at(left + i);
  }
  L.at(nl) = INF;

  for (size_t i = 0; i < nr; i++) {
    R.at(i) = S.at(mid + i);
  }
  R.at(nr) = INF;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    CNT++;
    if (L[i] <= R[j]) {
      S[k] = L[i++];
    } else {
      S[k] = R[j++];
    }
  }
}
void mergeSort(vector<int> &S, int left, int right) {
  if ((right - left) == 1) return;
  int mid = (left + right) / 2;
  mergeSort(S, left, mid);
  mergeSort(S, mid, right);
  merge(S, left, mid, right);
}
int main() {
  int n;
  cin >> n;
  vector<int> S(n);
  for (size_t i = 0; i < n; i++) {
    cin >> S.at(i);
  }

  mergeSort(S, 0, n);

  int i = 0;
  while (i != n - 1) {
    cout << S.at(i) << ' ';
    i++;
  }
  cout << S.at(i) << endl;
  cout << CNT << endl;
}
