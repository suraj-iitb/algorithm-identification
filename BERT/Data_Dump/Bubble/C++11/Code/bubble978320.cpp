#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int main(){

  int N,cnt=0;
  cin >> N;
  int A[N];
  rep(i,N) cin >> A[i];
  rep(i,N){
    for(int j=N-1;j>=i+1;j--){
      while(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        cnt++;
      }
    }
  }
  rep(i,N) {
    if( i ) cout << ' ';
    cout << A[i];
  } cout << endl;
  cout << cnt << endl;

  return 0;
}
