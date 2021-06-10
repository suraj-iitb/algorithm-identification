#include "bits/stdc++.h"
#include <random>
using namespace std;
using ll    =long long;    using dd   =double;        using pll    =pair<ll, ll>;  using tll    =tuple<ll,ll,ll>;
using vll   =vector<ll>;   using vdd  =vector<dd>;    using vpll   =vector<pll>;   using vtll   =vector<tll>;
using vvll  =vector<vll>;  using vvdd =vector<vdd>;   using vvpll  =vector<vpll>;  using vvtll  =vector<vtll>;
using vvvll =vector<vvll>; using vvvdd=vector<vvdd>;  using vvvpll =vector<vvpll>; using vvvtll =vector<vvtll>;
using vvvvll=vector<vvvll>;using vvvvdd=vector<vvvdd>;using vvvvpll=vector<vvvpll>;using vvvvtll=vector<vvvtll>;

constexpr ll INF = 1LL << 60;
constexpr dd EPS = 1e-11;
constexpr dd PI  = 3.1415926535897932;

//cin,cout高速化のおまじない＋桁数指定
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;

#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, S, E)  for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define dep(i, E, S)  for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define EACH(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmax(m,v[i]); return m;}//v[S]～v[E]の最大値
template<class T> inline T MinE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmin(m,v[i]); return m;}//v[S]～v[E]の最小値
template<class T> inline T MaxE(vector<T> &v, ll N) { return MaxE(v, 0, N - 1); } //先頭N個中の最大値
template<class T> inline T MinE(vector<T> &v, ll N) { return MinE(v, 0, N - 1); }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v, (ll)v.size()); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v, (ll)v.size()); }
template<class T> inline ll MaxI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]>v[m])m=i;} return m;}
template<class T> inline ll MinI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]<v[m])m=i;} return m;}
template<class T> inline ll MaxI(vector<T> &v, ll N) { return MaxI(v, 0, N - 1); }
template<class T> inline ll MinI(vector<T> &v, ll N) { return MinI(v, 0, N - 1); }
template<class T> inline ll MaxI(vector<T> &v) { return MaxI(v, (ll)v.size()); }
template<class T> inline ll MinI(vector<T> &v) { return MinI(v, (ll)v.size()); }
template<class T> inline T Sum(vector<T> &v, ll S,ll E){ T s=v[S]; REPS(i,S+1,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v, ll N) { return Sum(v, 0, N - 1); }
template<class T> inline T Sum(vector<T> &v) { return Sum(v, v.size()); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
template<class T> inline T POW(T a, ll n){ T r=1; for (; n>0; n>>=1, a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a, ll n){ return POW((ll)a, n); }
inline ll CEIL(ll a, ll b){ return (a+b-1)/b; }
ll Gcd(ll a, ll b){ return (b==0) ? a : Gcd(b, a%b); }
ll Lcm(ll a, ll b){ return a * b / Gcd(a, b); }
inline ll MSB(ll a){for(ll o=63,x=-1;;){ll m=(o+x)/2; if(a<(1LL<<m))o=m; else x=m; if(o-x==1)return x;}}
inline ll Upper2N(ll s) { return 1LL<<MSB(s)<<1; }//s<2^nなる最小の2^n
inline vll Bit2Idx(ll m){vll v; for(ll i=0;m;m>>=1,i++) if(m&1)v.push_back(i); return move(v);}
inline ll BitNum(ll m){ for (ll c=0;; m>>=1){ c+=m&1; if (!m)return c; } }
inline ll Bit(ll s, ll i){ return (s>>i)&1; } //sの第ibit i=0-63
inline ll BitOn(ll s, ll i){ return s|(1LL<<i); } //sの第ibitON i=0-63
inline ll BitOff(ll s, ll i){ return s&~(1LL<<i); } //sの第ibitOFF i=0-63
inline ll BitCut(ll s, ll i){ return s & (1LL<<++i)-1; }//sの第0～第ibitを抽出
inline vll str2num(string &s, ll N) {vll v(N); REP(i, N) v[i]=(ll)(s[i]-'0'); return move(v);}
inline vll ALP2num(string &s, ll N) {vll v(N); REP(i, N) v[i]=(ll)(s[i]-'A'); return move(v);}
inline vll alp2num(string &s, ll N) {vll v(N); REP(i, N) v[i]=(ll)(s[i]-'a'); return move(v);}
template<class T> inline ll FloorIdx(vector<T> &v, T x){ return upper_bound(ALL(v), x)-v.begin()-1; }
template<class T> inline ll CeilIdx(vector<T> &v, T x){ return lower_bound(ALL(v), x)-v.begin(); }
template<class T> inline ll UnderNumOf(vector<T> &v, T x){ //sort済vのx以下の個数を得る
	return upper_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T, class Pr> inline ll UnderNumOf(vector<T> &v, T x, Pr pred){ //x以下個数
	return upper_bound(v.begin(), v.end(), x, pred) - v.begin(); }
template<class T> inline ll OverNumOf(vector<T> &v, T x){ //sort済vのx以上の個数を得る
	return (ll)v.size() - (lower_bound(v.begin(), v.end(), x) - v.begin()); }
template<class T, class Pr> inline ll OverNumOf(vector<T> &v, T x, Pr pred){ //x以上の個数
	return (ll)v.size() - (lower_bound(v.begin(), v.end(), x, pred) - v.begin()); }

template<class T=ll> inline vector<T> cinv(ll N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
template<class T=ll, class S=ll> inline vector<pair<T, S>> cinv2(ll N){
	vector<pair<T, S>> v(N); REP(i,N){cin>>v[i].first>>v[i].second;} return move(v); }
template<class T=ll,class S=ll,class R=ll> inline vector<tuple<T, S, R>> cinv3(ll N){
	vector<tuple<T,S,R>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i]);} return move(v);}
template<class T=ll,class S=ll,class R=ll,class Q=ll> inline vector<tuple<T,S,R,Q>> cinv4(ll N){
	vector<tuple<T,S,R,Q>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i])>>get<3>(v[i]);} return move(v);}
template<class T=ll> inline vector<vector<T>> cinvv(ll N, ll M){
	vector<vector<T>> vv(N); REP(i, N) vv[i] = cinv(M); return move(vv);}
template<class T> inline void coutv(vector<T> &v, string d=" "){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?"":d);} cout<<'\n';}
template<class T> inline void coutv(deque<T> &v, string d=" "){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?"":d);} cout<<'\n';}
template<class T> void bye(T a){cout << a << '\n'; exit(0);}

#if defined(_DEBUG)
ll dumpW = 5;
template<class T> void Dump(vector<T> &v){
	REP(i, (ll)v.size()) { cerr << ((i==0)?"[":" ") << setw(dumpW) << v[i]; }  cerr << "]";
}
void Dump(vll &v){
	REP(i, (ll)v.size()) {
		cerr << ((i==0)?"[":" ") << setw(dumpW);
		if       (v[i] == INF) cerr << "INF";
		else if (v[i] == -INF) cerr << "-INF";
		else                   cerr << v[i];
	}  cerr << "]";
}
template<class T> void Dump(vector<vector<T>> &v){
	ll N=(ll)v.size();  string d[2][2]={{" ", "["},  {"\n", "]\n"}};
	REP(i, N) { cerr << d[0][i==0];  Dump(v[i]);  cerr << d[1][i==N-1]; }
}
template<class T> void Dump(vector<vector<vector<T>>> &v){
	ll N=(ll)v.size();  string d[2]={"  <", "[ <"};
	REP(i, N) { cerr << d[i==0] << i << ">\n"; Dump(v[i]); }  cerr << "]\n";
}
template<class T> void Dump(vector<vector<vector<vector<T>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ---<", "[ ---<"};
	REP(i, N) { cerr << d[i==0] << i << ">---\n"; Dump(v[i]); }  cerr << "]\n";
}
template<class T> void Dump(vector<vector<vector<vector<vector<T>>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ======<", "[ ======<"};
	REP(i, N) { cerr << d[i==0] << i << ">======\n"; Dump(v[i]); }  cerr << "]\n";
}
#else
template<class T> void Dump(vector<T> &v){}
template<class T> void Dump(vector<vector<T>> &v){}
template<class T> void Dump(vector<vector<vector<T>>> &v){}
template<class T> void Dump(vector<vector<vector<vector<T>>>> &v){}
template<class T> void Dump(vector<vector<vector<vector<vector<T>>>>> &v){}
#endif

template<ll MOD> struct mll_{
	ll val;
	mll_(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll_ operator - () const { return -val; }
	mll_ operator + (const mll_ &b) const { return val + b.val; }
	mll_ operator - (const mll_ &b) const { return val - b.val; }
	mll_ operator * (const mll_ &b) const { return val * b.val; }
	mll_ operator / (const mll_ &b) const { return mll_(*this) /= b; }
	mll_ operator + (ll b) const { return *this + mll_(b); }
	mll_ operator - (ll b) const { return *this - mll_(b); }
	mll_ operator * (ll b) const { return *this * mll_(b); }
	friend mll_ operator + (ll a, const mll_ &b) { return b + a; }
	friend mll_ operator - (ll a, const mll_ &b) { return -b + a; }
	friend mll_ operator * (ll a, const mll_ &b) { return b * a; }
	friend mll_ operator / (ll a, const mll_ &b) { return mll_(a)/b; }
	mll_ &operator += (const mll_ &b) { val=(val+b.val)%MOD; return *this; }
	mll_ &operator -= (const mll_ &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll_ &operator *= (const mll_ &b) { val=(val*b.val)%MOD; return *this; }
	mll_ &operator /= (const mll_ &b) {
		ll c=b.val, d=MOD, u=1, v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll_ &operator += (ll b) { return *this += mll_(b); }
	mll_ &operator -= (ll b) { return *this -= mll_(b); }
	mll_ &operator *= (ll b) { return *this *= mll_(b); }
	mll_ &operator /= (ll b) { return *this /= mll_(b); }
	bool operator == (const mll_ &b) { return val == b.val; }
	bool operator != (const mll_ &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll_(b); }
	bool operator != (ll b) { return *this != mll_(b); }
	friend bool operator == (ll a, const mll_ &b) { return mll_(a) == b.val; }
	friend bool operator != (ll a, const mll_ &b) { return mll_(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll_ &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll_ &a) { return is >> a.val; }
	static mll_ Combination(ll a, ll b){
		chmin(b, a-b);
		if (b<0) return mll_(0);
		mll_ c = 1;
		REP(i, b) c *= a-i;
		REP(i, b) c /= i+1;
		return c;
	}
};
using mll = mll_<1000000007LL>; //1000000007LL;// 998244353LL;
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;
using vvvvvmll = std::vector<vvvvmll>;


vll DijkstraOld(vector<vector<pll>> &to, ll s){
	ll N = (ll)to.size();
	vll dist(N, INF);
	priority_queue<pll, vpll, greater<pll>> Q;
	Q.push(pll(0, s));
	dist[s] = 0;
	while (!Q.empty()){
		ll d; ll v; tie(d, v) = Q.top(); Q.pop();
		if (d > dist[v]) continue;
		EACH(e, to[v]){
			ll u; ll c;  tie(u, c) = e;
			if (chmin(dist[u], dist[v]+c)) Q.push(pll(dist[u], u));
		}
	}
	return move(dist);
}

template<class T> vector<T> Dijkstra(vector<vector<pair<ll, T>>> &to, ll s){
	ll N = (ll)to.size();
	vector<T> dist(N, INF);
	priority_queue<pair<T, ll>, vector<pair<T, ll>>, greater<pair<T, ll>>> Q;
	Q.emplace(0, s);
	dist[s] = 0;
	while (!Q.empty()){
		T d; ll v; tie(d, v) = Q.top(); Q.pop();
		if (d > dist[v]) continue;
		EACH(e, to[v]){
			ll u; T c;  tie(u, c) = e;
			if (chmin(dist[u], dist[v]+c)) Q.emplace(dist[u], u);
		}
	}
	return move(dist);
}



template<class T=ll> vector<vector<pair<ll, T>>> cinWGraph(
					ll nodeNum, ll edgeNum, bool isDirected){ //無向false、有向true
	vector<vector<pair<ll, T>>> to(nodeNum);
	REP(i, edgeNum){
		ll v, u;  T c;  cin >> v >> u >> c;
		to[v].emplace_back(u, c);
		if (!isDirected) to[u].emplace_back(v, c);
	}
	return move(to);
}

void solve()
{
	ll v, e, r;  cin >> v >> e >> r;
	vector<vector<pair<ll, dd>>> to = cinWGraph<dd>(v, e, true);

	vector<dd> dist=Dijkstra(to, r);
	rep(i, 0, v-1){
		if (dist[i]+.1>=INF){
			cout << "INF" << '\n';
		}
		else{
			cout << (ll)(dist[i]+.5) << '\n';
		}
	}
}

int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1){
		solve();
	}
#endif
	return 0;
}

