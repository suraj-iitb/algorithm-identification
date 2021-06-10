#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vvd=vector<vd>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll>;
using tlll=tuple<ll,ll,ll>;
using vs=vector<string>;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n) range(i,0,n)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define range(i,a,n) for(ll i=(a);i<(n);i++)
#define LINF ((ll)1ll<<60)
#define INF ((int)1<<30)
#define EPS (1e-9)
#define MOD (1000000007ll)
#define fcout(a) cout<<setprecision(a)<<fixed
#define fs first
#define sc second
#define PI (3.1415926535897932384)

int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};
template<class T>bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}

template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}
template<class S,class T>void tf(bool b,S t,T f){if(b)puta(t);else puta(f);}
void YN(bool b){tf(b,"YES","NO");}
void Yn(bool b){tf(b,"Yes","No");}
void yn(bool b){tf(b,"yes","no");}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1;for(auto s:t){os<<(a?"":" ")<<s;a=0;}return os;}
template<class S>auto&operator>>(istream&is,vector<S>&t){for(S&a:t)cin>>a;return is;}

int popcnt(int x){return __builtin_popcount(x);}
int popcnt(ll x){return __builtin_popcountll(x);}
int bsr(int x){return 31 - __builtin_clz(x);}
int bsr(ll x){return 63 - __builtin_clzll(x);}
int bsf(int x){return __builtin_ctz(x);}
int bsf(ll x){return __builtin_ctzll(x);}

/*他のライブラリを入れる場所*/
template<class T=ll>struct Graph{
	int n;
	vector<vector<tuple<ll,T>>>edge;
	Graph(int N=1):n(N){edge.resize(n);}
	void add(ll f,ll t,T c,bool d=false){
		edge[f].emplace_back(t,c);
		if(!d)edge[t].emplace_back(f,c);
	}
	void view(){
		rep(i,n)for(auto&e:edge[i])
			puta(i,"=>",get<0>(e),", cost :",get<1>(e));
	}
};

template<class T=ll>struct Dijkstra:Graph<T>{
	using Graph<T>::Graph;
	Dijkstra(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		priority_queue<tuple<T,ll>> q;
		q.emplace(T(),s);
		while(!q.empty()){
			T c; ll p; tie(c,p)=q.top(); q.pop();
			if(ret[p]!=mval)continue;
			ret[p]=c=-c;
			for(auto&e:this->edge[p]){
				ll nxt;T cost;
				tie(nxt,cost)=e;
				if(ret[nxt]<=ret[p]+cost)continue;
				q.emplace(-ret[p]-cost,nxt);
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

template<class T=ll>struct BellmanFord:Graph<T>{
	using Graph<T>::Graph;
	BellmanFord(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<T>dist(ll s){
		vector<T> ret(this->n,mval);
		ret[s]=0;
		rep(i,2*this->n){
			rep(f,this->n)for(auto&e:this->edge[f]){
				ll t; T c; tie(t,c)=e;
				if(ret[f]!=mval && chmin(ret[t],ret[f]+c) && i+1>=this->n){
					ret[t]=-mval;
				}
			}
		}
		return ret;
	}
	T dist(ll s,ll t){return dist(s)[t];}
};

template<class T=ll>struct WarshallFloyd:Graph<T>{
	using Graph<T>::Graph;
	WarshallFloyd(int N=1):Graph<T>::Graph(N){}
	const T mval=numeric_limits<T>::max()/2;
	vector<vector<T>>dist(){
		vector<vector<T>> ret(this->n,vector<T>(this->n,mval));
		rep(i,this->n)ret[i][i]=0;
		rep(f,this->n)for(auto&e:this->edge[f]){
			ll t; T c; tie(t,c)=e; ret[f][t]=c;
		}
		rep(k,this->n)rep(i,this->n)if(ret[i][k]!=mval)
			rep(j,this->n)if(ret[k][j]!=mval)
				chmin(ret[i][j],ret[i][k]+ret[k][j]);
		return ret;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	WarshallFloyd<> g(n);
	rep(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		g.add(a,b,c,true);
	}
	auto ans=g.dist();
	rep(i,n)if(ans[i][i]<0){
		puta("NEGATIVE CYCLE");
		return 0;
	}
	rep(i,n){
		vs s;
		rep(j,n)s.push_back(ans[i][j]==g.mval?"INF":to_string(ans[i][j]));
		puta(s);
	}
	return 0;
}
