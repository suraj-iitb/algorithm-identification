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

// 参照じゃないとうまくいかない。なんで参照？？？
int bubbleSort(vi &A, int N){
  int count=0;
  bool flag = 1;
  int i=0;

  while(flag){
    flag = 0;
    for(int j=N-1; j>i; --j){
      if(A[j]<A[j-1]){
        swap(A[j], A[j-1]);
        flag = 1;
        ++count;
      }
    }
    ++i;
  }

  return count;
}

int main(){
  int N; cin >> N;
  vi A(N);
  for(int i=0; i<N; ++i) cin >> A[i];

  int count = bubbleSort(A, N);
  print(A, N);
  cout << count << endl;
}
