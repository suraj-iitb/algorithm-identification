#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
  int N,A[110];
  cin >> N;
  rep(i,N) cin >> A[i];
  
  int count = 0;
  
  rep(i,N){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(minj != i){
      swap(A[i],A[minj]);
      count++;
    }else{
      swap(A[i],A[minj]);
    }
  }

  rep(i,N-1) cout << A[i] << " ";
  cout << A[N-1] << endl;
  cout << count << endl;
}
