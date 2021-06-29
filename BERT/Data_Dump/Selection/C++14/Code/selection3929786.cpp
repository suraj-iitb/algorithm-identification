#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using graph = vector<vector<ll>>;
#define loop(i,n) for(ll i=0;i<n;i++)
#define Loop(i, m, n) for(ll i = m;i < n;i++)
#define pool(i,n) for(ll i=n-1;i>=0;i--)
#define Pool(i, m, n) for(ll i=n-1;i>=m;i--)
#define MAX 999999999ll
#define MIN -999999999ll

int main() {
  ll n;
  cin>>n;
  vec a(n);
  loop(i,n){
    cin>>a[i];
  }
  ll count=0;
  ll minj;
  loop(i,n){
  minj=i;
  Loop(j,i,n){
  if(a[minj]>a[j]){
  minj=j;
  }
  }
  if(i!=minj){
  swap(a[i],a[minj]);
  count++;
  }
  }
  loop(i,n){
  if(i>=1){
  cout<<" ";
  }
  cout<<a[i];
  }
  cout<<""<<endl;
  cout<<count<<endl;
}
