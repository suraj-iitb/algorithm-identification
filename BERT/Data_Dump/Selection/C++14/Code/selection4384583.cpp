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
  vector<ll> A(N);
  rep0(i,N){cin>>A[i];}
  for(ll i=0;i<N;i++){
      ll Min=i;
      for(ll j=i;j<N;j++){
          if(A[j]<A[Min]){Min=j;}
      }
      if(i!=Min){cnt++;}
      ll s=A[i];
      A[i]=A[Min];
      A[Min]=s;
  }
  rep0(i,N){if(i!=N-1){cout<<A[i]<<" ";} else{cout<<A[i]<<endl;}}
  cout<<cnt<<endl;
}
