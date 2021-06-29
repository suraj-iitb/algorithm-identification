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
   int a;
   cin>>a;
   vector<int> vec(a);
   rep(i,a){
       cin>>vec.at(i);
   }
   int sum=0;
   bool flag=true;
   while(flag){
       flag=false;
       for(int j=a-1;j>0;j--){
           if(vec.at(j)<vec.at(j-1)){
               int san=vec.at(j);
               vec.at(j)=vec.at(j-1);
               vec.at(j-1)=san;
               flag=true;
               sum++;
           }
       }
   }
   rep(i,a){
       if(i!=a-1){
        cout<<vec.at(i)<<" ";
       }
       else{
           cout<<vec.at(i)<<endl;
       }
   }
   cout<<sum<<endl;
}




