#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[100];
  int n,b,c=0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  int f = 1;
  while(f) {
    f = 0;
    for(int j = n-1; j >= 1; j--) {
      if(A[j] < A[j-1]) {
        b = A[j];
        A[j] = A[j-1];
        A[j-1] = b;
        c++;
        f = 1;
      }
    }
  }


  for(int i = 0; i < n; i++) {
    cout << A[i];
    if(i == n-1) cout << endl;
    else cout << " ";
  }
    cout << c << endl;
  return 0;
}

