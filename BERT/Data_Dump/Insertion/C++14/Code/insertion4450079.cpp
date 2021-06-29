#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

void func(vector<int> X){
  int n = X.size();
  REP(i, n){
    cout << X[i];
    if(i == n-1){
      cout << endl;
    }else{
      cout << " ";
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  func(A);
  for(int i = 1; i < N; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    func(A);
  }
}
