#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for (int i=0; i<N; i++) cin >> A[i];
  
  int v, j;  
  for (int i=0; i<N; i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for (int k=0; k<N; k++){
      if (k>0) cout << " ";
      cout << A[k];
    }
    cout << endl;
     
  }
  
}
