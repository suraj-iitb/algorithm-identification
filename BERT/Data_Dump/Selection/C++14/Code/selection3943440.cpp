#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MAX_M 100000
const int INF = 1e9;

int main (){
  int n,ans=0;
  cin>>n;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin>>A[i];
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(i!=minj){
      ans++;
      swap(A[i],A[minj]);
    }
  }
  for(int i=0;i<n;i++){
    cout<<A[i];
    if(i+1<n) cout<<" ";
  }
  cout<<endl;
  cout<<ans<<endl;
}
