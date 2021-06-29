#include <iostream>
#include <algorithm>
#define N 2000001
#define MAX 10000
using namespace std;

int main(){
  short A[N],B[N];
  int i,j,n;
  int C[MAX+1];
  cin >> n;
  for(i=1;i<=n;i++){cin >> A[i]; }
  
  for(j=0;j<=MAX;j++){C[j]=0; }
   for(j=1;j<=n;j++){C[A[j]]++; }
    for(j=1;j<=MAX;j++){C[j]+=C[j-1]; }

  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

    
  for(i=1;i<n;i++){cout << B[i] << " "; }
  cout << B[i] << endl;
  
  return 0;
}

