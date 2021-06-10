#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
#include <utility>
//#include <set>
//#include <map>
#include <queue>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
ll INF = 1000000000000 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

void Dijkstra(vector<vector<pll>> &g,vll &cnt,ll n,queue<ll> &q){
	for(int i=0;i<g.at(n).size();i++){
		if(cnt.at(g.at(n).at(i).first)>cnt.at(n)+g.at(n).at(i).second){
			q.push(g.at(n).at(i).first) ;
			cnt.at(g.at(n).at(i).first) = cnt.at(n)+g.at(n).at(i).second ;
		}
	}
	if(q.empty()) return ;
	ll sub = q.front() ;
	q.pop() ;
	Dijkstra(g,cnt,sub,q) ;
}

int main(){
	ll v,e,r ;
	cin >> v >> e >> r ;
	queue<ll> q ;
	vector<vector<pll>> g(v,vector<pll>(0)) ;
	for(int i=0;i<e;i++){
		ll s,t,d ;
		cin >> s >> t >> d ;
		g.at(s).push_back(make_pair(t,d)) ;
	}
	vll cnt(v,INF) ;
	cnt.at(r) = 0 ;
	Dijkstra(g,cnt,r,q) ;
	for(int i=0;i<v;i++){
		if(cnt.at(i)==INF) cout << "INF" << endl ;
		else cout << cnt.at(i) << endl ;
	}
}

