#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
typedef long long ll;
#define out(i) cout<<(i)<<endl

int main() {
  int N;
  cin>>N;
  vector<ll> vec(N);
  rep0(i,N){cin>>vec[i];}
  rep0(k,N){if(k<N-1){cout<<vec[k]<<" ";}else{cout<<vec[k]<<endl;}}
  rep1(i,N-1){
      int v=vec[i];
      int j=i-1;
      while(j>=0&&vec[j]>v){
          
          vec[j+1]=vec[j];
          j--;
          vec[j+1]=v;
      }
      rep0(k,N){if(k<N-1){cout<<vec[k]<<" ";}else{cout<<vec[k]<<endl;}}
  }
}

