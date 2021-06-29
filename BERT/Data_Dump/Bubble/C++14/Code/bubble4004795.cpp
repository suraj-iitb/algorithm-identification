#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int ans=0;
  bool f=1;
  while(f){
    f=0;
    for(int j=n-1;j>=1;j--){
      if(v[j]<v[j-1])swap(v[j],v[j-1]),ans++,f=1;
    }
  }
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<v[i];
  }
  cout<<endl;
  cout<<ans<<endl;
}

