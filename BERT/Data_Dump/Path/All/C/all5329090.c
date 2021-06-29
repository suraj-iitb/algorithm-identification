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
string solve(bool a) { return ((a) ? "Yes" : "No"); }
//隣接行列
//[s][t] (data)
template <typename T>
class pathMatrix {
public:
	vector<vector<T>> data;
	pathMatrix(int size): data(size, vector<T>(size, numeric_limits<T>::max() / 2)) {
		for (int i = 0; i < size; i++) {
			data[i][i] = 0;
		}
	}
	T undfined() { return numeric_limits<T>::max() / 2; }
	int size() { return this->data.size(); }
	const vector<T>& operator[](int s) const { return this->data[s]; }
	vector<T>& operator[](int s) { return this->data[s]; }
};
//include pathMarix
//ワーシャルフロイゼ法(隣接行列を受け取り、それぞれの最短を受け取る、size:10^2-)
template <typename T>
pathMatrix<T> WarshallFloyd(pathMatrix<T>& pathmatrix) {
	int index         = pathmatrix.size();
	pathMatrix<T> res = pathmatrix;
	for (int a = 0; a < index; a++) {
		for (int b = 0; b < index; b++) {
			for (int c = 0; c < index; c++) {
				chmin(res[b][c], res[b][a] + res[a][c]);
			}
		}
	}
	return (res);
}
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int v, e;
	//	bool negeat = false;
	cin >> v >> e;
	int s, t;
	ll d;
	pathMatrix<ll> path(v);
	rep(_, e) {
		cin >> s >> t >> d;
		path[s][t] = d;
	}
	path               = WarshallFloyd<ll>(path);
	pathMatrix<ll> com = WarshallFloyd<ll>(path);
	rep(i, v) rep(j, v) if (path[i][j] != com[i][j]) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	rep(i, v) {
		rep(j, v) {
			if (path[i][j] >= path.undfined() / 2) {
				cout << "INF";
			} else {
				cout << path[i][j];
			}
			if (j != v - 1) {
				cout << " ";
			} else {
				cout << endl;
			}
		}
	}
	//	cout << ans << endl;
}

