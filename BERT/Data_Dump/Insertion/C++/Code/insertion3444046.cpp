#include <bits/stdc++.h>
using namespace std;

//printVector(配列, 区切り文字)
template <typename T>
void printVector(vector<T> v, string delimiter) {
  for (int i=0; i<v.size(); i++) {
    if (i) cout << delimiter;
    cout << v[i];
  }
  cout << endl;
}

vector<int> insertionSort(vector<int> A) {
  for (int i=1; i<A.size(); i++) {
    printVector(A, " ");
    int tmp = A[i];
    int j = i-1;
    while (j>=0 && A[j]>tmp) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = tmp;
  }
  return A;
}
int main() {
  int n;
  cin >> n;

  std::vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  std::vector<int> b(n);
  b = insertionSort(a);
  printVector(b, " ");
}

