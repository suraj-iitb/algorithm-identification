#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct edge{
	int to;
	ll cost;
};

const int max_n = 101010;
vector<edge> g[max_n];

const ll INF = 1e17;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	rep(i, n) dist[i][i] = 0;

	rep(i, m){
		int a, b;
		ll d;
		cin >> a >> b >> d;
		dist[a][b] = d;
	}

	// 負の経路があるので、i->k, k->jのうち未更新の経路がある時点でcontinueしている
	rep(k, n){
		rep(i, n){
			if(dist[i][k] == INF) continue;
			rep(j, n){
				if(dist[k][j] == INF) continue;
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 負の閉路検知がこれらしい
	rep(i, n){
		if(dist[i][i] < 0){
			cout << "NEGATIVE CYCLE" << endl;
			exit(0);
		}
	}

	rep(i, n){
		rep(j, n){
			if(dist[i][j] == INF){
				cout << "INF";
			}else{
				cout << dist[i][j];
			} 
			cout << (j == n - 1 ? "\n" : " ");
		}
	}

}

