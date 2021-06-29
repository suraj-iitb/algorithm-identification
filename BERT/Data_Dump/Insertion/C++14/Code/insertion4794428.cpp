// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF;
    long double sum=0;
    long double minis=1000000000000;
    string str;
    cin>>n;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    ll num;
        rep(i,n) {
            cout<<v[i];
            if(i!=n-1) cout<<" ";
        }
        ln;
    REP(i,1,n){
        //i++;
        num=v[i];
        ll j=i-1;
        while(j>=0&&v[j]>num){
            v[j+1]=v[j];
            j--;
        }
        v[j+1] =num;
        rep(i,n) {
            cout<<v[i];
            if(i!=n-1) cout<<" ";
        }
        ln;
        //i--;
    }
    return 0;
}

