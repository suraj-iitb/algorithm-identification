#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    int m = i;
    for (int j = i; j < N; j++){
      if (A[j] < A[m]){
        m = j;
      }
    }
    if (i != m){
      swap(A[i], A[m]);
      ans++;
    }
  }
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
  cout << ans << endl;
}
