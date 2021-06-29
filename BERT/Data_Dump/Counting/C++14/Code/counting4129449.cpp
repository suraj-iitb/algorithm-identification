#include <iostream>
#include <vector>
using namespace std;
vector<int> A,B;

void CountingSort(int k,int n){
  vector<int> C(k+1,0);
  for(int j=0;j<n;j++){
    C[A[j]]++;
  }
  for(int i=1;i<=k;i++){
    C[i]+=C[i-1];
  }
  for(int j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  int n;
  cin>>n;
  A.resize(n);
  B.resize(n+1);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  CountingSort(10000,n);
  for(int i=1;i<=n;i++){
    cout<<B[i];
    if (i!=n) cout<<" ";
  }
  cout<<endl;
  return 0;
}

