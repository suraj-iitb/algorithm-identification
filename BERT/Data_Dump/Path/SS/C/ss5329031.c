#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << " " << p.second << ")";
	return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	rep(i, v.size()) {
		if (i) os << " ";
		os << v[i];
	}
	return os;
}
template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
	rep(i, v.size()) { is >> v[i]; }
	return is;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
#ifdef LOCAL
#define dbg(x) cerr << #x << ": " << (x) << '\n'
#define say(x) cerr << (x) << '\n'
#else
#define dbg(x)
#define say(x)
#endif

//目標までの距離
// ->t (data)
template <typename T>
class destination {
public:
	int t;
	T data;
	T undefined = std::numeric_limits<T>::max() / 2;
	destination(int t, T data) {
		this->t    = t;
		this->data = data;
	}
	destination() {
		this->t    = -1;
		this->data = undefined;
	}
};

// include destination
//隣接リスト
//[s] ->(t,data)
template <typename T>
class pathlist {
public:
	vector<vector<destination<T>>> data;
	pathlist(int size) : data(size){};
	void add(int s, destination<T> data) { this->data[s].push_back(data); }
	void add(int s, int t, T data) {
		(this->data)[s].push_back(destination<T>(t, data));
	}
	int size() { return this->data.size(); }
	const vector<destination<T>>& operator[](const int s) const {
		return this->data[s];
	}
	vector<destination<T>>& operator[](const int s) { return this->data[s]; }
};

// include destination
// include pathlist
//ダイクストラ法:スタートから任意の地点での最短距離、最短パスを求める
//計算量:(頂点+辺)log(頂点)
//始点,pathlist-->destination;
template <typename T>
vector<destination<T>> Dikstra(int start, pathlist<T> edge) {
	int v = edge.size();
	destination<T> at;
	vector<destination<T>> res(v, destination<T>(-1, at.undefined));
	res[start] = destination<T>(-1, 0LL);
	vector<bool> has(v, false);
	priority_queue<destination<T>, vector<destination<T>>,
	               function<bool(destination<T>, destination<T>)>>
	    q([](destination<T> a, destination<T> b = destination<T>()) {
		    return a.data > b.data;
	    });
	q.push(destination<T>(start, 0));
	at = q.top();
	while (!q.empty()) {
		at = q.top();
		q.pop();
		if (has[at.t]) continue;
		has[at.t] = true;

		for (auto itr = edge[at.t].begin(); itr != edge[at.t].end(); itr++) {
			if (res[itr->t].data > res[at.t].data + itr->data) {
				res[itr->t] = destination<T>(at.t, at.data + itr->data);
				q.push(destination<T>(itr->t, res[itr->t].data));
			}
		}
	}
	return res;
}

string solve(bool a) { return ((a) ? "Yes" : "No"); }
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int v, e, r;
	int ans = 0;
	r       = 0;
	cin >> v >> e >> r;
	pathlist<int> path(v);
	int s, t;
	ll w;
	rep(_, e) {
		cin >> s >> t >> w;
		path.add(s, t, w);
		//path.add(t, s, w);
	}
	//	return 0;
	vector<destination<int>> dis = Dikstra<int>(r, path);
	rep(i,v){
		if(dis[i].data==dis[i].undefined){
			cout << "INF" << endl;
		}else{
			cout << dis[i].data << endl;
		}
	}
//	cout << ans << endl;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
