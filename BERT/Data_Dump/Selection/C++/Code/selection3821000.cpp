#include <bits/stdc++.h>
using namespace std;

/* 選択ソート(0オリジン) */
int selectionSort(vector<int> &A, int N) {
  int i, j, sw = 0, minj;
  for ( i = 0; i < N - 1; i++ ) {
    minj = i;
    for ( j = i; j < N; j++ ) {
      if ( A.at(j) < A.at(minj) ) minj = j;
    }
    swap(A.at(i), A.at(minj));
    if ( i != minj ) sw++;
  }
  return sw;
}

int main() {
  int N, i, sw;
  cin >> N;
  vector<int> A(N);
  for ( i = 0; i < N; i++ ) cin >> A.at(i);
  
  sw = selectionSort(A, N);
  
  for ( i = 0; i < N; i++ ) {
    if ( i > 0 ) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
  cout << sw << endl;
  
  return 0;
}
