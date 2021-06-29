#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
using namespace std;

// 配列の要素を順番に出力
void trace(vector<int> A, int N){
  for (int i = 0; i < N; i++){
    if( i > 0 ) {cout << " ";}
    cout << A[i];
  }
  cout << "\n";
}

// 挿入ソート
void insertionSort(vector<int> A, int N){
  int j, i, v;
  for (int i = 1; i < N; i++){
    v = A[i];
    j = i-1;
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, N);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  trace(A, N);
  insertionSort(A, N);

  return 0;
}
