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

template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, r;
    cin >> N >> M >> r;
    Dijkstra<ll> dijk(N, LINF);
    REP(i,M){
        ll c, d, e;
        cin >> c >> d >> e;
        dijk.make_edge(c, d, e);
    }
    dijk.solve(r);
    REP(i,N){
        if(dijk.cost[i] == LINF) cout << "INF" << endl;
        else cout << dijk.cost[i] << endl;
    }
}
