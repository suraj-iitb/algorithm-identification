#include <bits/stdc++.h>
using namespace std;
#define int long long   // aaaaaaaaaaaaaaaaaa
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template<typename T, typename U>ostream& operator << (ostream& os, pair<T, U>& pair_var)
{os << "(" << pair_var.first << ", " << pair_var.second << ")";return os;}
// head

int x,s,t,m,n,k,res;
int a[501000] = {};
int b[501000] = {};
int c[501000] = {};
vector<PII> g[500010];
queue<int> que;
queue<int> que2;
priority_queue<PII> pque;
//string s;

signed main() {
	std::cin >>n>>m>>s;
	rep(i,0,m){
		std::cin >> a[i]>>b[i]>>c[i];
//		b[i]--,a[i]--;
		g[a[i]].pb(mp(b[i], c[i]));
//		g[b[i]].pb(mp(a[i], c[i]));
	}
	int d[100005];
	rep(i,0,n) d[i] = 1LL<<50;
	d[s] = 0;
	pque.push({0,s});
	while (!pque.empty()){
		PII p = pque.top();pque.pop();
		int prov_cost = p.first;
		int src = p.second;
		if(d[src]<prov_cost) continue;
		rep(i,0,g[src].size()){
			int dest = g[src][i].first;
			int weight = g[src][i].second;
			if ((d[dest] > d[src] + weight)){
				d[dest] = d[src] + weight;
				pque.push({-d[dest],dest});
			}
		}
	}
	rep(i,0,n){
		if(d[i] != 1LL<<50){
		std::cout << d[i] << '\n';
	}
	else{
		std::cout << "INF" << '\n';
	}
	}
}

