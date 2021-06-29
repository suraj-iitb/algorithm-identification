#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);
ll gcd(ll a, ll b) {if(b == 0) return a; else return gcd(b,a%b);}
ll lcm(ll a, ll b) {return a*b/gcd(a,b);}

const ll INF = (1LL<<60);

bool Warshall_Floyd(int V, vecvecl &d) {
    for(int i = 0; i < V; i++) d[i][i] = 0;
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (int i = 0; i < V; i++)
		if (d[i][i] < 0) return true;
	return false;
}

int main() {
    int N,M; cin >> N >> M;
    vecvecl dist(N,vecl(N,INF));
    REP(i,M) {
        int a,b; cin >> a >> b;
        ll c; cin >> c;
        dist[a][b] = c;
    }

    if(Warshall_Floyd(N,dist)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        REP(i,N) {
            REP(j,N) {
                if(dist[i][j] == INF) cout << "INF";
                else cout << dist[i][j];
                if(j < N-1) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}
