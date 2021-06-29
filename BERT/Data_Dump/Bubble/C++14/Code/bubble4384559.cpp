#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
typedef long long ll;
#define out(i) cout<<(i)<<endl

int main() {
  ll N,cnt=0;
  cin>>N;
  vector<ll> data(N);
  rep0(i,N){cin>>data[i];}
  ll flag=1;
  while(flag){
      flag=0;
      for(ll j=N-1;j>=1;j--){
          if(data[j]<data[j-1]){
              ll s=data[j];
              data[j]=data[j-1];
              data[j-1]=s;
              flag=1;
              cnt++;
          }
      }
      
  }
  rep0(i,N){if(i!=N-1){cout<<data[i]<<" ";} else{cout<<data[i]<<endl;}}
  cout<<cnt<<endl;
}
