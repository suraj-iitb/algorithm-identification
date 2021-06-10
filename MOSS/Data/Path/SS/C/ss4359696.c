#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>
using namespace std;
typedef  long long int lint;
//typedef pair<int, int> IP;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
#define mp make_pair
#define P pair<int,int>

int main() {
	int INF = 1000000000;
	int V, E, start;
	cin >> V >> E >> start;
	vector<vector<P>>G(V);
	rep(i, E) {
		int s, t, d;
		cin >> s >> t >> d;
		G[s].push_back(mp(t, d));
	}
	vector<int>dist(V, INF);//startからの距離を入れる配列。INF(未訪問)で初期化
	dist[start] = 0;
	priority_queue<P, vector<P>, greater<P>>que;//少ない値を優先するプライオリティキューを宣言
	que.push(mp(dist[start], start));

	while (!que.empty()) {
		P p = que.top();
		int v = p.second;
		que.pop();
		if (dist[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			P e = G[v][i];
			int u = e.first, cst = e.second;
			if (dist[u] > dist[v] + cst) {
				dist[u] = dist[v] + cst;
				que.push(mp(dist[u], u));
			}
		}
	}
	rep(i, V) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
}
