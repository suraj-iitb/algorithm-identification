#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int n) {
  int sw = 0;
  int minj;
  for (int i=0; i<n-1; i++) {
    minj = i;
    for (int j=i+1; j<n; j++) {
      if (A[minj] > A[j]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      sw++;
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
  
  sw = selectionSort(A, n);
  
  // バブルソート済み配列の出力
  for (int i=0; i<n; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
  return 0;
}
