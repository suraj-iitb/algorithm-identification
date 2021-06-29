#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<=(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define Eback(s) s.erase(s.end()-1,s.end())
#define rev(v) reverse(all(v))
#define minvec(v) *min_element(all(v))
#define maxvec(v) *max_element(all(v))
#define sumvec(v) accumulate(all(v),0LL)
#define mapmin(v) v.rbegin()->first
#define mapmax(v) v.begin()->first
#define pb push_back
#define pf push_front
#define m_p make_pair
#define DOUBLE fixed << setprecision(15)
#define OK cerr<<"OK\n"
#define OK1 cerr<<"OK1\n"
#define OK2 cerr<<"OK2\n"
#define sz(s) (long long)s.size()
#define INF ((1LL<<62)-(1LL<<31))
#define zero(x,n) setw(x) << setfill('0') << n
#define endl '\n'

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;

const double pi = acos(-1.0);
const ll mod=1000000007;
const ll mod2=998244353;

template<class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>&p) {
	ost << "{" << p.first << ", " << p.second << "} ";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost, const vector<T>&v) {
	ost << "{";
	for (int i = 0; i<(int)v.size(); i++) {
		if (i)ost << " ";
		ost << v[i];
	}
	ost << "} \n";
	return ost;
}

template<class A, class B>
ostream& operator<<(ostream& ost, const map<A, B>&v) {
	ost << "{";
	for (auto p:v) {
		ost << "{" << p.first << ", " << p.second << "} ";
	}
	ost << "} ";
	return ost;
}

void out(){cout << "\n";}
template<class T,class... Args>
void out(const T &x,const Args &... args){
	cout << x << " ";
	out(args...);
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
	for(T& e: vec) is >> e;
	return is;
}

template<typename T>
string join(vector<T>& vec, string sep=" "){
	stringstream ss;
	for(int i=0;i<(int)vec.size();i++){
		ss << vec[i] << (i+1==(int)vec.size()?"\n":sep);
	}
	return ss.str();
}

template<class T>
inline bool chmax(T& a, T b){if(a<b){a=b;return true;} return false;}

template<class T>
inline bool chmin(T& a, T b){if(a>b){a=b;return true;} return false;}

void YES(bool b) {cout << ((b)?"YES\n":"NO\n");}
void Yes(bool b) {cout << ((b)?"Yes\n":"No\n");}
void yes(bool b) {cout << ((b)?"yes\n":"no\n");}
void Yay(bool b) {cout << ((b)?"Yay!\n":":(\n");}

ll powmod(ll a,ll b){ll c=1; while(b>0){ if(b&1){ c=a*c%mod; } a=a*a%mod; b>>=1; } return c;}
ll nCrmod(ll n,ll r){ll x=1,y=1; for(ll i=0;i<r;i++) {x=x*(n-i)%mod; y=y*(i+1)%mod; } return x*powmod(y,mod-2)%mod;}
ll gcd(ll x, ll y) {return __gcd(x,y);}
ll lcm(ll x, ll y) {return x/__gcd(x,y)*y;}

int main()
{
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    ll ans=0;
    rep(i,n){
        for(ll j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                ans++;
            }
        }
    }
    cout << join(a) << ans << endl;
	return 0;
}
