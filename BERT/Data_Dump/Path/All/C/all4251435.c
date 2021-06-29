#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

ll dist[111][111];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, E;
    cin >> N >> E;
    REP(i,N) REP(j,N) if(i != j) dist[i][j] = LINF;

    REP(i,E){
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    REP(k,N) REP(i,N) REP(j,N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    bool ok = true;
    REP(k,N) REP(i,N) REP(j,N) if(chmin(dist[i][j], dist[i][k] + dist[k][j])) ok = false;
    if(!ok){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    REP(i,N){
        REP(j,N){
            if(dist[i][j] > 1e10) cout << "INF";
            else cout << dist[i][j];
            if(j != N - 1) cout << " ";
        }
        cout << endl;
    }
}
