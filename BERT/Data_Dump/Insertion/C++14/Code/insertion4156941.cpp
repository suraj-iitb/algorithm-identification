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
    long long a;
    cin>>a;
    vector<long long> vec(a);
    rep(i,a){
        cin>>vec.at(i);
    }
    long long v;
    rep(i,a){
        v=vec.at(i);
        long long j=i-1;
        while(j>=0&&vec.at(j)>v){
            vec.at(j+1)=vec.at(j);
            j--;
        }
        vec.at(j+1)=v;
        rep(i,a){
            cout<<vec.at(i);
            if(i==a-1){
                cout<<endl;
            }        
            else{
                cout<<" ";
            }
        }
    }
}




