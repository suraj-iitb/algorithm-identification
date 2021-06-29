#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const long long INF=1LL << 60;
long long a,b;
long long dp[100200][110];
long long w[110],v[110];


int main(){
  int n;
  cin>>n;
  vector<int> vec(n);
  rep(i,n){
      cin>>vec.at(i);
  }
  int num=0;
  rep(i,n-1){
      int minj=i;
      for(int j=i;j<n;j++){
          if(vec.at(j)<vec.at(minj)){
              minj=j;
          }
      }
      if(i!=minj){
          num++;
      }
        int tes=vec.at(i);
        vec.at(i)=vec.at(minj);
        vec.at(minj)=tes;
        //num++;
        
      //} 
  }
  rep(i,n){
      cout<<vec.at(i);
      if(i!=n-1){
          cout<<" ";
      }
      else{
          cout<<endl;
      }
  }
  cout<<num<<endl;

}




