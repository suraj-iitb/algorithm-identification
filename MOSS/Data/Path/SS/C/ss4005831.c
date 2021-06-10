#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define str string
#define ld long double
#define vec vector
#define vll vec<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define kai "\n"
#define yuque priority_queue
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mie min_element
#define mae max_element
#define tos to_string
#define sep setprecision
#define lob lower_bound
#define upb upper_bound
#define nep next_permutation
#define MOD 1000000007ll
#define MIN (1e-10)
#define equal(a,b) (abs((a)-(b))<MIN)
#define v2 ten
#define chokusen senbun
#define kakkei vec<ten>
using namespace std;
void solve();
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed;
	solve();
}
struct pea{
	ll f,s;
	bool operator<(const pea &p)const{
		return f!=p.f?f<p.f:s<p.s;
	};
};
struct tri{
	ll f,s,t;
	bool operator<(const tri &p)const{return f<p.f;};
};
class ten{
public:
	ld x,y;
	ten operator+(ten p){return{x+p.x,y+p.y};}
	ten operator-(ten p){return{x-p.x,y-p.y};}
	ten operator*(ld k){return{k*x,k*y};}
	ten operator/(ld k){return{x/k,y/k};}
	ld abs(){return sqrt(abs2());}
	ld abs2(){return x*x+y*y;};
	bool operator<(const ten &p)const{return x!=p.x?x<p.x:y<p.y;};
	bool operator==(const ten &p)const{
		return (-MIN<x-p.x)&&(x-p.x<MIN)&&(-MIN<y-p.y)&&(y-p.y<MIN);
	};
	ld naiseki(v2 b){return x*b.x+y*b.y;}
	ld gaiseki(v2 b){return x*b.y-y*b.x;}
};
struct senbun{ten p1,p2;};
struct en{ten o;ld r;};
void dijkstra(const vec<vec<pea>> &c,ll v,vll &d){
	d[v]=0;
	ll n=c.size();
	ll count=1;
	vec<bool> seen(n,false);
	seen[v]=true;
	yuque<pea> hen;
	rep(i,0,c[v].size())hen.push({-c[v][i].f,c[v][i].s});
	while(count!=n){
		if(hen.empty())break;
		pea k=hen.top();hen.pop();
		while(seen[k.s]){
			if(hen.empty()){
				count=-1;
				break;
			}
			k=hen.top();
			hen.pop();
		}
		if(count==-1)break;
		d[k.s]=-k.f;
		count++;
		seen[k.s]=true;
		rep(i,0,c[k.s].size())hen.push({k.f-c[k.s][i].f,c[k.s][i].s});
	}
}
void solve(){
	ll v,e,r;cin>>v>>e>>r;
	vec<vec<pea>> c(v);
	rep(i,0,e){
		ll s,t,d;cin>>s>>t>>d;
		c[s].pub({d,t});
	}
	vll ans(v,MOD);
	dijkstra(c,r,ans);
	rep(i,0,v){
		if(ans[i]==MOD)cout<<"INF"<<kai;
		else cout<<ans[i]<<kai;
	}
}
