#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define pi 3.1415926535897932384

int main(){
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];

  bool flag = true;
  int cnt = 0;

  while (flag) {
    flag = false;
    for (int j=N-1;j>=1;j--){
      if (A[j]< A[j-1]){
        swap(A[j], A[j-1]);
        cnt++;
        flag = true;
      }
    }
  }

  rep(i,N){
    cout << A[i];
    if (i<N-1) cout << " ";
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}

 
