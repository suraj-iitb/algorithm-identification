#include<bits/stdc++.h>
//#define int long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define rep(N) for (int i = 0; i < N; ++i)
#define Rep(a, b) for (int i = a; i < b; ++i)
#define For(i, N) for (int i = 0; i < N; ++i)
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define makei(N) int N; cin >> N;
#define makes(s) string s; cin >> s;
#define maked(d) double d; cin >> d;
#define makev(v, N) vi v(N); rep(N)cin >> v[i];
#define mod 1000000007

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pis = pair<int, string>;
using msi = map<string, int>;

template<typename T>
void say(T s) {
	cout << s << "\n";
}

template<typename T>
void say(vector<T> s) {
	auto itr = s.begin();
	cout << *(itr++);
	while (itr != s.end()) {
		cout << " " << *(itr++);
	}
	cout << "\n";
}

template<typename T>
void say(vector<T> s, char r) {
	auto itr = s.begin();
	cout << *(itr++);
	while (itr != s.end()) {
		cout << r << *(itr++);
	}
	cout << "\n";
}

void yn(bool b) {
	if (b)say("yes");
	else say("no");
}

void Yn(bool b) {
	if (b)say("Yes");
	else say("No");
}

void YN(bool b) {
	if (b)say("YES");
	else say("NO");
}

template<typename T>
void maxi(T& a, T b) {
	a = max(a, b);
}

template<typename T>
void mini(T& a, T b) {
	a = min(a, b);
}

void exact_say(double x) {
	cout << setprecision(numeric_limits<double>::max_digits10) << x << endl;
}

template<typename T>
vector<vector<T>> fill_vector(int h, int w, T val) {
	vector<vector<T>> ret;
	vector<T> v(w, val);
	rep(h)ret.push_back(v);
	return ret;
}

template<typename T>
T max(vector<T> v) {
	T ret = v[0];
	Rep(1, v.size())maxi(ret, v[i]);
	return ret;
}

template<typename T>
T min(vector<T> v) {
	T ret = v[0];
	Rep(1, v.size())mini(ret, v[i]);
	return ret;
}

signed main() {
	makei(n);
	makev(a, n);
	Rep(1, n + 1) {
		sort(a.begin(), a.begin() + i);
		say(a);
	}
}
