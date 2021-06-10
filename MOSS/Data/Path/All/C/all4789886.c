// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX/10-1
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

    ll a,b,c,m,n,maxi=0,f=0,g=0,mini=INF,sum=0;
    ll k;
    string str,stra;
    ll V,e;
    cin>>V>>e;
    ll d[V][V];
    rep(i,V)rep(j,V) {
        if(i==j) d[i][j]=0;
        else d[i][j]=INF;
    }
    rep(i,e){
        cin>>a>>b>>c;
        d[a][b]=c;
        //d[b][a]=c;
    }
    rep(k,V)rep(i,V)rep(j,V){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    rep(i,V){
        if(d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    rep(i,V){
        rep(j,V){
            if(d[i][j]<(ll)mod*100)cout<<d[i][j];
            else cout<<"INF";
            if(j!=V-1) cout<<" ";
        }
        ln;
    }
    return 0;
}

