#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int n) {
  int sw = 0;
  bool flag = 1;
  for (int i=0; flag; i++) {
    flag = 0;
    for (int j=n-1; j>=i+1; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        sw++;
        flag = 1;
      }
    }
  }
  return sw;
}


int main() {
  int n;
  cin >> n;
  int sw = 0;
  int A[n];
  for (int i=0; i<n; i++) cin >> A[i];
  
  sw = bubbleSort(A, n);
  
  // バブルソート済み配列の出力
  for (int i=0; i<n; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
  return 0;
}
