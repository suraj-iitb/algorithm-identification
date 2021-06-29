#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000

int main(){
  int N; cin >> N;
  int A[N];
  rep(i,N) cin >> A[i];

  // selection sort
  int cnt = 0;
  for (int i=0;i<N;i++){
    int minj = i;
    for (int j=i;j<N;j++){
      if (A[j]<A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if (i!=minj) cnt++;
  }

  rep(i,N){
    cout << A[i];
    if (i<N-1) cout << " ";
  }
  cout << endl;

  cout << cnt << endl;
}
