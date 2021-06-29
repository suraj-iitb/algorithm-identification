#include <iostream>
#define N 2000000

using namespace std;

int main(){
  int i, j, n, k=0;
  int A[N], B[N], C[N];

  cin >> n;
  for(i=0;i<n;++i){
    cin >> A[i];
    if(A[i] > k) k = A[i];
  }
  
  for(i=0;i<=k;++i)C[i] = 0;
  for(i=0;i<n;++i)C[A[i]]++;
  for(i=0;i<=k;++i)C[i] += C[i-1];
  for(j=n-1;j>=0;--j){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
  
  for(i=0;i<n;++i){
    cout << B[i];
    if(i != n-1)cout << " ";
  }
  cout << "\n";
  return 0;
}

