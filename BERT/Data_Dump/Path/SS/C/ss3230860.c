# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans,
a[400000], b[400000];
vector<LL> d, dp1, d_p, d_q;
string str, ss;
bool f;
char c[3000][3000];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<vector<Edge>>vec;
vector<edge>ed;
vector<LL>v;
map<Pll,LL>ma;
multiset<LL>st;

void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
vector<LL> dijk(vector<vector<Edge>> &g,LL s) {
	vector<LL>dis(g.size());
	rep(i, g.size()) {
		dis[i] = INF;
	}
	dis[s] = 0;
	priority_queue<Pll, vector<Pll>, greater<Pll>>pq;
	pq.push(Pll(0, s));
	while (!pq.empty()) {
		Pll num = pq.top();
		pq.pop();
		LL v = num.sec, cost = num.fir;
		if (dis[v] < cost)continue;
		rep(i, g[v].size()) {
			if (dis[g[v][i].to] > dis[v] + g[v][i].cost) {
				dis[g[v][i].to] = dis[v] + g[v][i].cost;
				pq.push(Pll(dis[g[v][i].to], g[v][i].to));
			}
		}
	}
	return dis;
}	
LL dfs(LL s,LL p_cos,LL q_cos) {
	LL ret = min({ p_cos + d_q[s], q_cos + d_p[s],p_cos + q_cos });
	rep(i, vec[s].size()) {
		LL next = vec[s][i].to;
		if (d[s] <= d[next])continue;
		if (d[s] == d[next] + vec[s][i].cost) {
			ret = min(ret, dfs(next, min(p_cos, d_p[next]), min(q_cos, d_q[next])));
		}
	}
	return ret;
}

int main() {
	cin >> n >> m>>s;
	/*
	cin >> s >> t;
	cin >> p >> q;
	s--, t--, p--, q--;
	*/
	vec.resize(n);
	rep(i, m) {
		LL x, y, z;
		cin >> x >> y >> z;
		//x--, y--;
		vec[x].push_back(Edge{ y,z });
		//vec[y].push_back(Edge{ x,z });
	}
	d = dijk(vec, s);
	/*
	d_p = dijk(vec, p);
	d_q = dijk(vec, q);
	cout << min(dfs(t, d_p[t], d_q[t]), d_p[q]) << endl;
	*/

	rep(i, n) {
		if(d[i] == INF)
		cout << "INF" << endl;
		else
			cout <<d[i] << endl;
	}
	return 0;
}
