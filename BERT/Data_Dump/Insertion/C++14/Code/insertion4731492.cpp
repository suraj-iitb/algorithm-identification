#include <bits/stdc++.h>
using namespace std;
// 型エイリアス
using pii = pair<int, int>;
using tisb = tuple<int, string, bool>;
using vi = vector<int>;
using vii = vector<vi>;

void print(vi A, int N){
  for(int i=0; i<N; ++i){
    if(i>0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void insertionSort(vi A, int N){
  for(int i=1; i<N; ++i){
    int v = A[i];
    int j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      --j;
    }
    A[j+1] = v;
    print(A, N);
  }
}

int main(){
  int N; cin >> N;
  vi A(N);
  for(int i=0; i<N; ++i) cin >> A[i];
  
  print(A, N);
  insertionSort(A, N);
}
