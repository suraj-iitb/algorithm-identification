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

int selectionSort(vi &A, int N){
  int count = 0;

  for(int i=0; i<N; ++i){
    int minj = i;

    for(int j=i; j<N; ++j){
      if(A[j] < A[minj]) minj = j;
    }
    
    swap(A[i], A[minj]);
    if(minj != i) ++count;
  }

  return count;
}

int main(){
  int N; cin >> N;
  vi A(N);
  for(int i=0; i<N; ++i) cin >> A[i];

  int count = selectionSort(A, N);
  print(A, N);
  cout << count << endl;
}
