#include<bits/stdc++.h>
using namespace std;

int part(vector<pair<int,char>>&a,int p,int r){
  int x=a[r-1].first,i=p-1;
  for(int j=p;j<r-1;j++){
    if(a[j].first<=x){
      swap(a[++i],a[j]);
    }
  }
  swap(a[i+1],a[r-1]);
  return i+1;
}
void qkst(vector<pair<int,char>>&a,int p,int r){
  if(p<r){
    int q=part(a,p,r);
    qkst(a,p,q);
    qkst(a,q+1,r);
  }
}

int main(){
  int n;
  cin>>n;
  vector<pair<int,char>>a(n);
  map<int,queue<char>>st;
  for(int i=0;i<n;i++)cin>>a[i].second>>a[i].first;
  for(int i=0;i<n;i++)st[a[i].first].push(a[i].second);
  vector<pair<int,char>>b=a;
  qkst(a,0,n);
  bool sta=true;
  for(int i=0;i<n;i++){
    if(a[i].second!=st[a[i].first].front())sta=false;
    st[a[i].first].pop();
  }
  cout<<(sta?"Stable\n":"Not stable\n");
  for(int i=0;i<n;i++)cout<<a[i].second<<' '<<a[i].first<<'\n';
}
