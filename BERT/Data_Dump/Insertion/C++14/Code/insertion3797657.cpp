#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  
  int n;cin>>n;
  vector<int>v(n);
  rep(i,n)cin>>v[i];
  rep(i,n){
    int k=i;while(true){
    if(v[k]<v[k-1]&&k>0){
      int a=v[k];
      v[k]=v[k-1];
      v[k-1]=a;
      k--;
    }
    else break;
    }
  rep(i,n){
    if(i)cout<<' ';
    cout<<v[i];
  }
  cout<<endl;
  }
}

