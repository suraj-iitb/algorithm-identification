#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int comparisonCount = 0;

void merge(vector<int>& A, int left, int mid, int right) {
  vector<int> L(A.begin() + left, A.begin() + mid);
  vector<int> R(A.begin() + mid, A.begin() + right);
  int i = 0;
  int j = 0;
  L.push_back(INT_MAX);
  R.push_back(INT_MAX);
  for (int k = left; k < right; ++k) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    ++comparisonCount;
  }
}

void mergeSort(vector<int>& A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }

  mergeSort(S, 0, S.size());

  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << S[i];
  }
  cout << endl;
  cout << comparisonCount << endl;
}

