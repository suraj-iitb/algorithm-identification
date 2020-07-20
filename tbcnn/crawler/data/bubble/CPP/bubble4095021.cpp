#include <bits/stdc++.h>
#include <iostream>
#include <string> 
using namespace std;
int main(){
  int n;
  cin >> n;
  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int i,j,m;
  int ans = 0;
    for(int i = 0; i < n; i++) {
    for(int j = n - 1; j > i; j--) {
      if(A[j] < A[j - 1]) {
        m = A[j];
        A[j] = A[j - 1];
        A[j - 1] = m;
        ans++;
      }
    }
    }
  for(i = 0; i < n; i++){
    cout << A[i];
    if(i < n - 1){
      cout << " ";
    }
  }
  cout << endl;
      cout << ans << endl;
      return 0;
}

