//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
//#include <intrin.h>  //AtCoder (gcc) 上ではこれがあると動かない。__popcnt用のincludeファイル。
using namespace std;

typedef long long ll;
typedef long double ld;


#define int long long
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define sqrt(d) pow((long double) (d), 0.50)

const int INF = 2000000000; //2e9
const long long INF2 = 8000000000000000000; //8e18

const int large_P = 1000000007; //1e9 + 7
//const int large_P = 1000000009; //1e9 + 9
//const int large_P = 998244353;




//繰り返し2乗法
//N^aの、Mで割った余りを求める。
ll my_pow(ll N, ll a, ll M) {
	ll tempo;
	if (a == 0) {
		return 1;
	}
	else {
		if (a % 2 == 0) {
			tempo = my_pow(N, a / 2, M);
			return (tempo * tempo) % M;
		}
		else {
			tempo = my_pow(N, a - 1, M);
			return (tempo * N) % M;
		}
	}
}




//N_C_a を M で割った余り
ll my_combination(ll N, ll a, ll M) {
	ll answer = 1;

	rep(i, a) {
		answer *= (N - i);
		answer %= M;
	}

	rep(i, a) {
		answer *= my_pow(i + 1, M - 2, M);
		answer %= M;
	}

	return answer;
}




ll my_gcd(ll& a, ll& b) {
	if (b == 0) return a;
	ll temp = a % b;
	return my_gcd(b, temp);
}




// base を底としたときの、n の i桁目を、v.at(i) に入れる。(桁数は n に応じて自動で設定する。)
void ll_to_vector(int base, long long n, vector<int>& v) {
	long long tempo = n;
	long long tempo2 = n;

	int n_digit = 1;
	while (tempo2 >= 10) {
		tempo2 /= 10;
		n_digit++;
	}

	v.assign(n_digit, 0);

	//ll n_digit = v.size();  // v のサイズをそのままにする場合。

	for (int i = 0; i < n_digit; i++) {
		v.at(i) = tempo / pow(base, n_digit - 1 - i);
		tempo -= v.at(i) * pow(base, n_digit - 1 - i);
	}
}




int char_to_int(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4;
	case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
	default: return 0;
	}
}




//エラトステネスの篩で、prime で ないところに false を入れる。
//true で初期化された vector を代入する必要がある。
void prime_judge(vector<bool>& prime_or_not) {

	prime_or_not.at(0) = false;
	prime_or_not.at(1) = false;

	ll n = prime_or_not.size() - 1;
	ll region = (ll)sqrt(n) + 1;

	for (ll i = 2; i <= n / 2; i++) {
		prime_or_not.at(2 * i) = false;
	}


	for (ll i2 = 1; i2 < n / 2; i2++) {
		ll i = 2 * i2 + 1;  //ここからは奇数のみ探索
		if (i < region && prime_or_not.at(i)) {
			ll j = i * i;
			while (j < n + 1) {
				prime_or_not.at(j) = false;
				j += 2 * i;
			}
		}
	}
};




map<ll, ll> divide_to_prime(int target) {
	map<ll, ll> res;

	//sqrt(target) まで調べる。
	ll upper_lim = ceil(sqrt(target));
	vector<bool> prime_or_not(upper_lim + 1, true);

	if (upper_lim < 20) prime_or_not.assign(25, true);
	prime_judge(prime_or_not);

	ll tempo = target;
	rep(i, (upper_lim + 1)) {
		if (prime_or_not.at(i)) {
			while (tempo % i == 0) {
				tempo /= i;
				res[i]++;
			}
		}
	}

	if (tempo != 1) res[tempo]++; //sqrt(target) より大きな素因数は高々1つしかない。



	return res;
}




void BFS_labyrinth(queue<pair<int, int>>& que, vector<vector<int>>& dist, int& area) {
	int n = dist.size();
	int m = dist.at(0).size();

	while (!que.empty()) {
		int temp_i, temp_j;
		pair<int, int> tempo = que.front(); que.pop();

		temp_i = tempo.first;
		temp_j = tempo.second;
		//cout << temp_i << " " << temp_j << endl;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (temp_i + i < 0 || n <= temp_i + i) continue;  //範囲外
				if (temp_j + j < 0 || m <= temp_j + j) continue;  //範囲外
				if (i == 0 && j == 0) continue; //動いていない
				if (i * j != 0) continue; //右上など。八近傍の場合は消す。
				if (dist.at(temp_i + i).at(temp_j + j) != -1) continue; //行けない領域に、既に INF などが代入されている場合はこの条件だけで ok

				dist.at(temp_i + i).at(temp_j + j) = dist.at(temp_i).at(temp_j) + 1;
				que.push(make_pair(temp_i + i, temp_j + j));
			}
		}

		//何か所も領域がある場合だけ必要
		if (que.empty()) {
			rep(i, n) {
				rep(j, m) {
					if (dist.at(i).at(j) == -1) {
						que.push(make_pair(i, j));
						dist.at(i).at(j) = 0;
						area++;
						break;
					}
				}
				if (!que.empty()) break;
			}
		}
	}
}




void dfs(const vector<vector<int>> G, vector<bool>& seen, int v) {
	seen.at(v) = true;

	for (int next_v : G.at(v)) {
		if (seen.at(next_v)) continue;
		dfs(G, seen, next_v);
	}
}



class edge {
public:
	int to;
	int cost;
};

void dijkstra(int s, const vector<vector<edge>> G, vector<int>& dis) {
	int V = dis.size(); //頂点数
	dis.assign(V, INF);

	//first が最短距離、second が頂点番号。
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dis.at(s) = 0; que.push(make_pair(0, s));

	while (!que.empty()) {
		pair<int, int> p = que.top(); que.pop();
		int v = p.second;
		if (dis.at(v) < p.first) continue;  //最短距離がすでに更新されているので無視。

		for (edge e : G.at(v)) {
			if (dis.at(e.to) > dis.at(v) + e.cost) {
				dis.at(e.to) = dis.at(v) + e.cost;
				que.push(make_pair(dis.at(e.to), e.to));
			}
		}
	}
}




class UnionFind {
public:
	vector<int> parent;
	vector<int> rank;

	UnionFind(int N) : parent(N), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;
		return parent.at(x) = root(parent.at(x));
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		if (rx == ry) return; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
		}
		else {
			parent.at(ry) = rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
		}
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}


};




class wUnionFind {
public:
	vector<int> parent;
	vector<int> diff_weight; //親との差分。
	vector<int> rank;

	wUnionFind(int N) : parent(N), diff_weight(N, 0), rank(N, 0) {
		rep(i, N) {
			parent.at(i) = i;
		}
	}

	int root(int x) {
		if (parent.at(x) == x) return x;

		int r = root(parent.at(x));
		diff_weight.at(x) += diff_weight.at(parent.at(x)); //累積和
		return parent.at(x) = r;
	}

	int weight(int x) {
		root(x);
		return diff_weight.at(x);
	}

	//weight.at(y) - weight.at(x) == w となるようにする。
	bool unite(int x, int y, int w) {
		int rx = root(x);
		int ry = root(y);
		int diff_weight_to_ry_from_rx = w + weight(x) - weight(y);

		if (rx == ry) return false; //xの根とyの根が同じなので、何もしない。
		if (rank.at(rx) < rank.at(ry)) {
			parent.at(rx) = ry;
			diff_weight.at(rx) = -diff_weight_to_ry_from_rx;
		}
		else {
			parent.at(ry) = rx;
			diff_weight.at(ry) = diff_weight_to_ry_from_rx;
			if (rank.at(rx) == rank.at(ry)) rank.at(rx)++;
		}

		return true;
	}

	bool same(int x, int y) {
		return (root(x) == root(y));
	}


};




signed main() {
	int V, E, S;
	cin >> V >> E >> S;

	vector<vector<edge>> G(V);
	rep(i, E) {
		int s, t, d;
		//cin >> s >> t >> d;
		scanf("%lld %lld %lld", &s, &t, &d);

		edge e1, e2;
		e1.to = s; e2.to = t;
		e1.cost = d; e2.cost = d;

		//G.at(t).push_back(e1);
		G.at(s).push_back(e2);	
	}

	vector<int> dis(V, INF);
	dijkstra(S, G, dis);

	rep(i, V) {
		if (dis.at(i) == INF) cout << "INF" << endl;
		//else cout << dis.at(i) << endl;
		else printf("%d\n", dis.at(i));

	}
}
