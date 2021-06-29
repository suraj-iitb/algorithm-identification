#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
// http://sesenosannko.hatenablog.com/entry/2017/09/01/214852
// https://beta.atcoder.jp/contests/abc061/submissions/3322496
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3166760#1
// 0-index
struct Bellman_Ford{
	struct edge{ll from, to, cost;};
	ll inf = 1e16;
	vector<edge> es;
	vector<ll> d;
	ll V,E;
	void init(ll v,ll e){
		V = v; E = e;
		d.resize(V);
	}
	void shortest_path(ll s){
		FOR(i,0,V) d[i] = inf;
		d[s] = 0;
		FOR(i,0,V){
			FOR(j,0,E){
				edge e = es[j];
				if(d[e.from]!=inf && d[e.to]>d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
				}
			}
		}
	}
	bool find_negative_loop(){// all graph
		FOR(i,0,V)d[i] = 0;
		FOR(i,0,V){
			FOR(j,0,E){
				edge e = es[j];
				if(d[e.to]>d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					if(i == V-1) return true;
				}
			}
		}
		return false;
	}
	bool find_negative_loop(ll s){// from s
		ll cnt = 0;
		FOR(i,0,V)d[i]=inf;
		d[s]=0;
		while(true){
			bool update = false;
			cnt++;
			FOR(i,0,E){
				edge e = es[i];
				if(d[e.from] != inf && d[e.to]>d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					if(cnt == V){
						return true;
					}
					update = true;
				}
			}
			if(! update)break;
		}
		return false;
	}
	bool shortest_path(int s, int t){ // t: destination
		FOR(i,0,V)d[i] = inf;
		d[s] = 0;
		FOR(i,0,2*V){
			FOR(j,0,E){
				edge e = es[j];
				if(d[e.from]!=inf && d[e.to]>d[e.from] + e.cost){
					d[e.to] = d[e.from] + e.cost;
					if(i>=V-1 && e.to==t) return true;
				}
			}
		}	
		return false;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll V,E;
	cin >> V >> E;
	ll d[V][V];
	FOR(i,0,V){
		FOR(j,0,V){
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	Bellman_Ford bf;
	bf.init(V,E);
	FOR(i,0,E){
		ll a,b,c;
		cin >> a >> b >> c;
		d[a][b] = c;
		bf.es.push_back({a,b,c});
	}
	if(bf.find_negative_loop()){
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	FOR(k,0,V){
		FOR(i,0,V){
			FOR(j,0,V){
				if(d[i][k]!=INF && d[k][j]!=INF)
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	FOR(i,0,V){
		FOR(j,0,V){
			if(j!=0)cout << " ";
			if(d[i][j]==INF){
				cout << "INF";
			}else{
				cout << d[i][j];
			}
		}
		cout << endl;
	}

}

