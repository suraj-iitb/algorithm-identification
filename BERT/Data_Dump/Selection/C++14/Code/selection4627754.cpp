#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int ans = 0;
int selectionSort(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i+1; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    if (A[i] != A[minj]) {

    swap(A[i], A[minj]);
    ans ++;
    }
  }

  rep(i, N){
    if (i != N-1) cout << A[i] << " ";
    else cout << A[i];
  }
  cout << endl;
  return 0;
}

int main()
{
  int N;cin>>N;
  vector<int> A(N);
  rep(i, N) cin>>A[i];
  selectionSort(A, N);
  cout<<ans<<endl;
  return 0;
}
