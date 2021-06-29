#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ld eps = 1e-9;
const db PI = atan(1) * 4;

template<typename T, typename S>inline bool upmin(T&a, const S&b) { return a > b ? a = b, 1 : 0; }
template<typename T, typename S>inline bool upmax(T&a, const S&b) { return a < b ? a = b, 1 : 0; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a;
	}
	ll ans = pow(a, b / 2);
	ans *= ans;
	ans *= b % 2 == 1 ? a : 1;
	return ans;
}

namespace SOLVE {
	struct edge {
		ll from, to, weight;
	};

	struct vertex {
		ll distance = 1e15, no;
	};

	struct compareVertex {
		bool operator() (vertex const& p1, vertex const& p2) {
			return p1.distance > p2.distance;
		}
	};



	void main() {
		ll V, E, s, t1, t2, t3;
		cin >> V >> E >> s;

		vector<vector<edge> > edges(V + 5);
		REP(i, 0, E) {
			cin >> t1 >> t2 >> t3;
			edge e;
			e.from = t1;
			e.to = t2;
			e.weight = t3;
			edges[t1].push_back(e);
		}

		VLL ans(V + 5, 1e15);
		VLL finalised(V + 5, 0);

		priority_queue<vertex, vector<vertex>, compareVertex> pq;
		vertex start;
		start.distance = 0;
		start.no = s;
		pq.push(start);
		

		while (sz(pq)) {
			vertex top = pq.top();
			//cout << top.no << endl;
			pq.pop();

			if (finalised[top.no] == 1) {
				continue;
			}
			ans[top.no] = top.distance;
			finalised[top.no] = 1;

			for (edge e : edges[top.no]) {
				if (top.distance + e.weight < ans[e.to]) {
					vertex v;
					v.distance = top.distance + e.weight;
					v.no = e.to;
					pq.push(v);
				}
			}
		}

		REP(i, 0, V) {
			if (ans[i] == 1e15) {
				cout << "INF\n";
			}
			else {
				cout << ans[i] << endl;
			}
		}




	}
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	//    in(t);
	t = 1;
	while (t--) {
		SOLVE::main();

	}

	return 0;
}
