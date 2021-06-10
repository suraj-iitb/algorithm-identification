#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF         1e9
#define INFLL       1e18
#define EPS         1e-9
#define REP(i,n)    for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(ll i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP(n)     cout << fixed << setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

signed main()
{
	ll v = in(), e = in();
	vector<vector<ll>>adj(v, vector<ll>(v, INFLL)); REP(i, v)adj[i][i] = 0;
	REP(i, e) {
		ll s = in(), t = in(), d = in();
		adj[s][t] = d;
	}
	REP(k, v) {
		REP(i, v) {
			REP(j, v) {
				if (adj[i][k] != INFLL && adj[k][j] != INFLL) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
	REP(i, v) {
		if (adj[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	REP(i, v) {
		REP(j, v) {
		    if(j != 0){
		        cout << ' ';
		    }
			if (adj[i][j] == INFLL) {
				cout << "INF";
			} else {
				cout << adj[i][j];
			}
		}
		cout << endl;
	}
}
