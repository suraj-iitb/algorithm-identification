#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MAX 2000005

int main() {
  int n; cin >> n;
  short A[MAX], B[MAX];
  int C[10001] = {0};

  for(int i=0; i<n; ++i) {
    cin >> A[i+1];
    ++C[A[i+1]];
  }

  for(int i=1; i<=10000; ++i) C[i] += C[i-1];

  for(int i=1; i<=n; ++i) {
    B[C[A[i]]] = A[i];
    --C[A[i]];
  }

  for(int i=0; i<n; ++i) {
    if(i) cout << " ";
    cout << B[i+1];
  }
  cout << endl;
}

