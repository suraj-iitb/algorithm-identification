#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define pi 3.1415926535897932384

int main(){
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];

  rep(i,N){
      cout << A[i];
      if (i!=N-1) cout << " ";
    }
  cout << endl;

  int tmp;
  for (int i=1; i<N; i++){
    tmp = A[i];
    int j = i-1;
    while (j>=0 && A[j]>tmp) {
      A[j+1] = A[j];
      --j;
    } 
    A[j+1] = tmp;

    rep(i,N){
      cout << A[i];
      if (i!=N-1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}

 
