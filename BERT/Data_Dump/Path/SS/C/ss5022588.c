#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct Dijkstra {
	private:
		struct Edge {int to; ll cost; };
		int n;
		vector<vector<Edge>> es;
		vector<ll> dist;
	public:
		Dijkstra(int _n): n(_n), es(_n), dist(_n){}
		void add_edge(int from, int to, ll cost) {
			es[from].push_back(Edge{to, cost});
		}
		void solve(int s) {
			rep(i,n) dist[i] = LINF;
			dist[s] = 0;
			priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
			q.push(pair<ll,int>(0, s));
			while (!q.empty()) {
				pair<ll,int> p = q.top(); q.pop();
				int v = p.second;
				if (dist[v] < p.first) continue;
				for (Edge e: es[v]) {
					if (dist[e.to] > p.first + e.cost) {
						dist[e.to] = p.first + e.cost;
						q.push(pair<ll,int>(dist[e.to], e.to));
					}
				}
			}
		}
		ll get_dist(int u) {
			return dist[u];
		}
};

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	Dijkstra g(n);
	rep(i,m) {
		int a, b; ll c;
		cin >> a >> b >> c;
		g.add_edge(a, b, c);
	}
	g.solve(s);
	rep(i,n) {
		ll ans = g.get_dist(i);
		if (ans == LINF) cout << "INF" << endl;
		else cout << ans << endl;
	}
}
