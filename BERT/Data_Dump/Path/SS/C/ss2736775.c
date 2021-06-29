#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <random>

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { ostr << ", " << *itr; }	ostr << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const stack<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; } stack<_Ty> t(s); ostr << "{" << t.top(); t.pop(); while (!t.empty()) { ostr << ", " << t.top(); t.pop(); } ostr << "}";	return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << l.front(); for (auto itr = ++l.begin(); itr != l.end(); ++itr) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& istr, pair<_KTy, _Ty>& m) { istr >> m.first >> m.second; return istr; }
template <typename _Ty> istream& operator >> (istream& istr, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) istr >> v[i]; return istr; }
namespace aux { // print tuple
	template<typename Ty, unsigned N, unsigned L> struct tp { static void print(ostream& os, const Ty& v) { os << get<N>(v) << ", "; tp<Ty, N + 1, L>::print(os, v); } };
	template<typename Ty, unsigned N> struct tp<Ty, N, N> { static void print(ostream& os, const Ty& value) { os << get<N>(value); } };
}
template<typename... Tys> ostream& operator<<(ostream& os, const tuple<Tys...>& t) { os << "{"; aux::tp<tuple<Tys...>, 0, sizeof...(Tys)-1>::print(os, t); os << "}"; return os; }

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-11
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fake false



class Dijkstra {
	using int_t = long long;
	using pii = pair<int_t, int>;
	using Queue = priority_queue<pii, vector<pii>, greater<pii>>;

	const int_t INF = int_t(1) << 55;
	
public:
	int_t V;
	vector<vector<pii>>& G;
	vector<int_t> dist;
	vector<bool> used;
	Queue pq;

	Dijkstra(vector<vector<pii>>& G, int_t V) : V(V), G(G), dist(V, INF), used(V, false) {}

	void calc_shortest_path(int s) {
		pq.push(pii(0, s));
		while (!pq.empty()) {
			int_t d; int t;
			tie(d, t) = pq.top(); pq.pop();
			if (used[t]) continue;
			used[t] = true; dist[t] = d;
			for (pii e : G[t]) {
				if (dist[e.second] <= d + e.first) continue;
				pq.push(pii(d + e.first, e.second));
			}
		}
	}

	vector<int_t> get_shortest_path() { return dist; }
	int_t get_shortest_path(int t) { return dist[t]; }
};

int main()
{
	//clock_t start, end;
	//start = clock();

	cin.tie(0);
	ios::sync_with_stdio(false);

	using pii = pair<ll, int>;

	int V, E, s;
	cin >> V >> E >> s;

	vector<vector<pii>> G(V);
	REP(i, E) {
		int from, to, cost;
		cin >> from >> to >> cost;
		G[from].push_back(pii(cost, to));
	}

	Dijkstra ds(G, V);

	ds.calc_shortest_path(s);
	for (int i = 0; i < V; i++) {
		ll d = ds.get_shortest_path(i);
		cout << (d >= (1LL << 55) ? "INF" : to_string(d)) << endl;
	}

	//end = clock();
	//printf("%d msec.\n", end - start);

	return 0;
}
