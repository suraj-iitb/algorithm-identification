#include <bits/stdc++.h>
using namespace std;

void vec_show(vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (i == vec.size() - 1)
      cout << vec[i];
    else
      cout << vec[i] << " ";
  }
  cout << endl;
}

void insertSort(vector<int> &vec) {
  for (int i = 1; i < vec.size(); ++i) {
    int x = vec[i];
    int j = i - 1;
    while (vec[j] > x && j >= 0) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = x;
    vec_show(vec);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  vec_show(A);
  insertSort(A);
}
