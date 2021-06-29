#include<bits/stdc++.h>
#define fr(i,n) for(int i=0;i<(n);++i)
#define foor(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,n) for(int i=(n);i--;)
#define roof(i,b,a) for(int i=(b);i>=(a);--i)
#define elsif else if
#define all(x) x.begin(),x.end()
#define Sort(x) sort(all(x))
#define Reverse(x) reverse(all(x))
#define PQ priority_queue
#define NP(x) next_permutation(all(x))
#define M_PI 3.14159265358979323846
using namespace std;            typedef vector<bool> vb; typedef vector<vb>  vvb;
                                typedef vector<int>  vi; typedef vector<vi>  vvi;
typedef long long ll;           typedef vector< ll>  vl; typedef vector<vl>  vvl;
typedef unsigned long long ull; typedef vector<ull>  vu; typedef vector<vu>  vvu;
typedef double dbl;             typedef vector<dbl>  vd; typedef vector<vd>  vvd;
typedef string str;             typedef vector<str>  vs; typedef vector<vs>  vvs;
typedef pair<int,int>pii;       typedef vector<pii>vpii; typedef map<int,int>mii;
typedef pair< ll, ll>pll;       typedef vector<pll>vpll; typedef map< ll, ll>mll;
typedef pair<dbl,dbl>pdd;       typedef vector<pdd>vpdd; typedef map<dbl,dbl>mdd;
typedef pair<str,str>pss;       typedef vector<pss>vpss; typedef map<str,str>mss;
typedef pair<int, ll>pil;       typedef vector<pil>vpil; typedef map<int, ll>mil;
typedef pair< ll,int>pli;       typedef vector<pli>vpli; typedef map< ll,int>mli;
typedef pair<dbl,int>pdi;       typedef vector<pdi>vpdi; typedef map<dbl,int>mdi;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T>set<T>&operator<<(set<T>&s,const T t){s.insert(t);return s;}
template<typename T>stack<T>&operator<<(stack<T>&s,const T t){s.push(t);return s;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator<<(PQ<T,vector<T>,U>&q,const T t){q.push(t);return q;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T>istream&operator>>(istream&s,vector<T>&v){fr(i,v.size()){s>>v[i];}return s;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
//template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<endl;}return s;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){fr(i,v.size()){i?s<<" "<<v[i]:s<<v[i];}return s;}
template<typename T,typename U>pair<T,U>operator+(pair<T,U>a,pair<T,U>b){return {a.first+b.first,a.second+b.second};}
template<typename T,typename U>pair<T,U>operator-(pair<T,U>a,pair<T,U>b){return {a.first-b.first,a.second-b.second};}
template<typename T>void print(T x){cout<<x<<endl;}
template<typename T,typename U>void print(T x,U y){cout<<x<<" "<<y<<endl;}
template<typename T,typename U,typename V>void print(T x,U y,V z){cout<<x<<" "<<y<<" "<<z<<endl;}
void YN(bool b){print(b?"YES":"NO");}void PI(bool b){print(b?"POSSIBLE":"IMPOSSIBLE");}
void Yn(bool b){print(b?"Yes":"No");}void Pi(bool b){print(b?"Possible":"Impossible");}
void yn(bool b){print(b?"yes":"no");}void pi(bool b){print(b?"possible":"impossible");}
const int MD=1e9+7;
template<typename T>str to_string(const T&n){ostringstream s;s<<n;return s.str();}
template<typename T,typename U>vector<pair<T,U>>dijkstra(const vector<vector<pair<T,U>>>E,const U s,const T inf){using P=pair<T,U>;vector<P>d;fr(i,E.size()){d<<P{inf,i};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
template<typename T,typename U>map<U,pair<T,U>>dijkstra(map<U,vector<pair<T,U>>>E,const U s,const T inf){using P=pair<T,U>;map<U,P>d;for(pair<U,vector<P>>e:E){d[e.first]=P{inf,e.first};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
template<typename T>T distsq(pair<T,T>a,pair<T,T>b){return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);}
template<typename T>T max(const vector<T>a){T m=a[0];for(T e:a){m=max(m,e);}return m;}
template<typename T>T min(const vector<T>a){T m=a[0];for(T e:a){m=min(m,e);}return m;}
template<typename T>T gcd(const T a,const T b){return a?gcd(b%a,a):b;}
template<typename T>T gcd(const vector<T>a){T g=a[0];for(T e:a){g=gcd(g,e);}return g;}
template<typename T>vector<T>LIS(const vector<T>A){vi B;for(T a:A){auto it=lower_bound(all(B),a);if(it==B.end()){B<<a;}else{*it=a;}}return B;}
class UnionFind{vi p,r,s;public:UnionFind(int N){p=r=vi(N);s=vi(N,1);fr(i,N){p[i]=i;}}int find(int i){return p[i]=p[i]==i?i:find(p[i]);}void unite(int a,int b){if(r[a=find(a)]>r[b=find(b)]){swap(a,b);}s[b]+=s[a];r[p[a]=b]+=r[a]==r[b];}bool same(int a,int b){return find(a)==find(b);}int size(int x){return s[find(x)];}};
ll strmod(const str&s,const int m){ll x=0;fr(i,s.size()){x=(x*10+s[i]-48)%m;}return x;}
vvl mul(const vvl&A,const vvl&B,const int m){vvl C;fr(y,A.size()){C<<vl(B[y].size());}fr(y,C.size()){fr(x,C[y].size()){fr(i,A[0].size()){(C[y][x]+=A[y][i]*B[i][x])%=m;}}}return C;}
vvl pow(const vvl&A,const ll n,const int m){vvl B;fr(y,A.size()){B<<vl(A.size());}if(n==0){fr(i,B.size()){B[i][i]=1;}}elsif(n%2){B=mul(A,pow(A,n-1,m),m);}else{vvl C=pow(A,n/2,m);B=mul(C,C,m);}return B;}
ll pow(const ll a,const ll n,const int m){ll t;return n?(n&1?a>=0?a%m:~-m+~a%m:1)*(t=pow(a,n>>1,m),t*t%m)%m:!!a;}
ll inv(const ll x,const int p){return pow(x,p-2,p);}
vpll fact(const int n,const int p){vpll v(n+1);v[0].first=1;foor(i,1,n){v[i].first=v[i-1].first*i%p;}v[n].second=inv(v[n].first,p);roof(i,n,1){v[i-1].second=v[i].second*i%p;}return v;}
ll C2(const int n){return(ll)n*~-n/2;}
ll sum(const vi a){ll s=0;for(int e:a){s+=e;}return s;}
ll sum(const vl a){ll s=0;for(ll e:a){s+=e;}return s;}
ll segsum(vl&s,int l,int r){l|=s.size()>>1;r|=s.size()>>1;if(l>r){return 0;}if(l==r){return s[l];}ll z=s[l]+s[r];for(;l>>1<r>>1;l>>=1,r>>=1){l&1||(z+=s[l^1]);r&1&&(z+=s[r^1]);}return z;}
void segadd(vl&s,int i,ll x){s[i|=s.size()>>1]+=x;for(;i>>1>=1;i>>=1){s[i>>1]=s[i]+s[i^1];}}
ll BITsum(vl&B,int i){ll z=0;while(i>0){z+=B[i];i-=i&-i;}return z;}
void BITadd(vl&B,int i,ll x){while(i<B.size()){B[i]+=x;i+=i&-i;}}
ll fib(const ll n,const int m){ll a,b,c,d,A,B,C,D;a=1;b=0;c=0;d=1;rf(i,63){A=a*a+b*c;B=a*b+b*d;C=c*a+d*c;D=c*b+d*d;if(n>>i&1){a=A;b=B;c=C;d=D;A=a+b;B=a;C=c+d;D=c;}a=A%m;b=B%m;c=C%m;d=D%m;}return b;}
vi primes(int n){vb b(n+1);vi p;foor(i,2,n){if(!b[i]){p<<i;for(int j=2*i;j<=n;j+=i){b[j]=true;}}}return p;}
vb isprime(const int n){vb v(n+1,true);v[0]=v[1]=false;foor(i,2,n){if(v[i]){for(int j=2*i;j<=n;j+=i){v[j]=false;}}}return v;}
// (int) * (int) => (int)
// (int) / (int) => (int)

int main(){cin.tie(0);ios::sync_with_stdio(false);
	int N,M,r;cin>>N>>M>>r;
	vector<vpli>E(N);
	fr(i,M){
		int s,t;ll d;cin>>s>>t>>d;
		E[s]<<pli{d,t};
	}
	vpli d=dijkstra(E,r,ll(1e18));
	fr(i,N){
		if(d[i].first<1e18){
			print(d[i].first);
		}else{
			print("INF");
		}
	}
	return 0;
}

