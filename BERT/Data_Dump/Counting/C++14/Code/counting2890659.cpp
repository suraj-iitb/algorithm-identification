#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void countingSort(vector<int>& A, vector<int>& B, int k) {
  vector<int> C(k, 0);
  for (int i = 0; i < A.size(); ++i) {
    ++C[A[i]];
  }
  for (int i = 1; i < k; ++i) {
    C[i] = C[i] + C[i - 1];
  }
  for (int i = A.size() - 1; i >= 0; --i) {
    int x = A[i];
    B[--C[x]] = x;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  vector<int> B(n);
  countingSort(A, B, 10001);

  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << B[i];
  }
  cout << endl;
}

