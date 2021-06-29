#include <bits/stdc++.h>
using namespace std;
int n;

void CountingSort(vector<int>& A,vector<int>& B,int k){
  int i,j,C[k+1];
  for(i=0;i<=k;i++)C[i]=0;
  for(j=1;j<=n;j++)C[A[j]]++;
  for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  int i,j,ans,max_a=0;
  cin >> n;
  vector<int>A(n+1);
  vector<int>B(n+1);
  for(i=1;i<=n;i++){
    cin >> A[i];
    max_a = max(max_a,A[i]);
  }

  CountingSort(A,B,max_a);
  
  for(i=1;i<n;i++)
    cout << B[i] << " ";
  cout << B[i] << endl;
  
  return 0;
}

