#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;


template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

struct edge{
	int from,to;
	int cost;
	edge(int to,int cost):to(to),cost(cost){
	}
};

vector<int>dijkstra(vector<vector<edge>> &g,int s){
	const int inf=numeric_limits<int>::max();
	vector<int>dis(g.size(),inf);
	dis[s]=0;
	using P=pair<int,int>;
	priority_queue<P,vector<P>,greater<P>>pq;
	pq.emplace(s,0);
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		int x=p.first;
		if(dis[x]<p.second)continue;
		for(auto e:g[x]){
			if(chmin(dis[e.to],dis[x]+e.cost)){
				pq.emplace(e.to,dis[e.to]);
			}
		}
	}
	return dis;
}
void solve(){
	int v,e,r;
	cin>>v>>e>>r;
	vector<vector<edge>>g(v);
	rep(i,e){
		int s,t,d;
		cin>>s>>t>>d;
		g[s].emplace_back(t,d);
	}
	const int inf =numeric_limits<int>::max();
	auto dis=dijkstra(g,r);
	rep(i,v){
		if(dis[i]==inf){
			cout<<"INF\n";
		}
		else cout<<dis[i]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

