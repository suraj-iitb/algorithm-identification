#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
  int N,A[110];
  cin >> N;
  rep(i,N){
    cin >> A[i];
  }
  int count = 0;

  int flag = 1; // 逆の隣接要素が存在する
  while(flag){
    flag = 0;
    for(int j = N - 1; j >= 1; j--){
      if(A[j] < A[j-1]){
        swap(A[j],A[j-1]);
        count++;
        flag = 1;
      }       
    }
  }

  rep(i,N-1){
    cout << A[i] << " ";
  }
  cout << A[N-1] << endl;
  cout << count << endl;
}

