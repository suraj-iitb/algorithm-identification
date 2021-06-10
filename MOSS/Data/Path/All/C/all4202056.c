
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define veci vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))


using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
//template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
//template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x:vec) is >> x;
    return is;
}
const ll INF=1e10+100;

ll v;
ll d[105][105];
void floyd(){
    rep(k,v){
        rep(i,v){
            if(d[i][k]==INF) continue;
            rep(j,v){
                if(d[k][j]==INF) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    ll e;
    cin >> v >> e;
    rep(i,v){
        rep(j,v){
            d[i][j]=((i==j)?0:INF);
        }
    }
    rep(i,e){
         ll s,t,c;
        cin >> s >> t >> c;
        d[s][t]=c;
    }
    floyd();
    bool negative=false;
    rep(i,v){
        if(d[i][i]<0){
            negative=true;
        }
    }
    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        rep(i,v){
            rep(j,v){
                if(j) cout << " ";
                if(d[i][j]==INF) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
} 
