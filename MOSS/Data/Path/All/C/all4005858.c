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
#define MOD 1000000007999ll
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
bool floyd(vec<vll> &d){
	ll n=d.size();
	rep(i,0,n)d[i][i]=0;
	rep(k,0,n){
		rep(i,0,n){
			if(d[i][k]!=MOD){
				rep(j,0,n){
					if(d[k][j]!=MOD){
						d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
					}
				}
			}
		}
	}
	bool b=true;
	rep(i,0,n)if(d[i][i]<0)b=false;
	return b;
}
void solve(){
	ll v,e;cin>>v>>e;
	vec<vll> d(v,vll(v,MOD));
	rep(i,0,e){
		ll s,t,w;
		cin>>s>>t>>w;
		d[s][t]=w;
	}
	if(!floyd(d))cout<<"NEGATIVE CYCLE"<<kai;
	else{
  	rep(i,0,v){
	  	if(d[i][0]!=MOD)cout<<d[i][0];
  		else cout<<"INF";
	  	rep(j,1,v){
  			if(d[i][j]!=MOD)cout<<' '<<d[i][j];
  			else cout<<" INF";
  		}
  		cout<<kai;
	  }
	}
}
