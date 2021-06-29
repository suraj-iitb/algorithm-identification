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
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=1;i<n;i++){
      if(A[i-1]>A[i]){
        swap(A[i-1],A[i]);
        ans++;
        flag=true;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<A[i];
    if(i+1<n) cout<<" ";
  }
  cout<<endl;
  cout<<ans<<endl;
}
