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
    for (int j = N - 1; j > i; j--){
      if (A[j] < A[j - 1]){
        swap(A[j], A[j - 1]);
        ans++;
      }
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
