#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);};};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL<<40;//62


class WAR_FLY {
public:
    vector<vector<ll> > d; //辺の数
    ll V; //頂点の数
    
    WAR_FLY(ll n) {
        V = n;
        d = vector<vector<ll> > (n,vector<ll>(n));
        for(ll i = 0; i < V; i++) {
            for(ll j = 0; j < V; j++) {
                if(i == j) {
                    d[i][j] = 0;
                }
                else {
                    d[i][j] = LLINF;
                }
            }
        }
    }

    void warshall_floyd() {
        for(ll k = 0; k < V; k++) {
            for(ll i = 0; i < V; i++) {
                for(ll j = 0; j < V; j++) {
                    d[i][j] = min((ll)d[i][j], (ll)d[i][k] + (ll)d[k][j]);
                }
            }
        }
    }

    void add(ll from, ll to, ll cost) {
        d[from][to] = cost;
    }

    bool is_negative_loop() {
        for(ll i = 0; i < V; i++) {
            if(d[i][i] < 0) return true;
        }
        return false;
    }

    void show() {
        for(ll i = 0; i < V; i++) {
            for(ll j = 0; j < V; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void){

    ll v,e,s,t,d;
    cin>>v>>e;
    WAR_FLY wa(v);
    rep(i,e){
        cin>>s>>t>>d;
        wa.add(s,t,d);
    }
    wa.warshall_floyd();
    // wa.show();
    if(wa.is_negative_loop()){
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }
    rep(i,v){
        rep(j,v){
        if(wa.d[i][j]>=INF)cout<<"INF";
        else cout<<wa.d[i][j];
        if(j!=v-1)cout<<' ';
        }
        cout<<endl;
    }
}
