#include "bits/stdc++.h"
using namespace std;

template< int mod >
struct ModInt {
	int x;
	ModInt() : x(0) {}
	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
	ModInt& operator+=(const ModInt& p) {
		if ((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt & operator-=(const ModInt & p) {
		if ((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt & operator*=(const ModInt & p) {
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}
	ModInt& operator/=(const ModInt & p) {
		*this *= p.inverse();
		return *this;
	}
	ModInt& operator^=(int64_t n) {
		int y = x;
		x = 1;
		while (n > 0) {
			if (n & 1) x = 1LL * x * y % mod;
			y = 1LL * y * y % mod;
			n >>= 1;
		}
		return *this;
	}
	ModInt operator-() const { return ModInt(-x); }
	ModInt operator+(const ModInt & p) const { return ModInt(*this) += p; }
	ModInt operator-(const ModInt & p) const { return ModInt(*this) -= p; }
	ModInt operator*(const ModInt & p) const { return ModInt(*this) *= p; }
	ModInt operator/(const ModInt & p) const { return ModInt(*this) /= p; }
	ModInt operator^(const int64_t n) const { return ModInt(*this) ^= n; }
	bool operator==(const ModInt & p) const { return x == p.x; }
	bool operator!=(const ModInt & p) const { return x != p.x; }
	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		return ModInt(u);
	}
	friend ostream& operator<<(ostream & os, const ModInt< mod > & p) {
		return os << p.x;
	}
	friend istream& operator>>(istream & is, ModInt< mod > & a) {
		int64_t t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}
};

using i64 = long long;
using ui64 = unsigned long long;
using ld = long double;

constexpr int INF = (1 << 30);
constexpr i64 INF64 = (1ll << 60);
constexpr int MOD = 1e9 + 7;
const double PI = 3.1415926535;

template <typename T>
using pque = priority_queue<T>;
template <typename T>
using rpque = priority_queue<T, vector<T>, greater<T>>;
using vint = vector<int>;
using vi64 = vector<i64>;
using vstr = vector<string>;
using P = pair<int, int>;
template <int mod>
using mint = ModInt<mod>;
//using mint = ModInt<MOD>;

#define rep(i,N) for(int i=0;i<(int)(N);++i)
#define rep1(i,N) for(int i=1;i<=(int)(N);++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a,b) for(int i=(int)a;i<(int)(b);++i)
#define fs first
#define sc second
#define e_b emplace_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),v.end())

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

template <class T, class U>
ostream & operator<<(ostream & os, const pair<T, U> & p) {
	return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& operator<<(ostream & os, const vector<T> & v) {
	os << "[";
	for (auto& e : v) os << e << ", ";
	return os << "]";
}

template <class T, class U>
ostream& operator<<(ostream & os, const map<T, U> & m) {
	os << "{" << endl;
	for (auto& e : m) os << "(" << e.first << ", " << e.second << ")" << endl;
	return os << "}";
}

template <typename T>
void print(T v) {
	if (v.size() == 0) return;
	else cout << v[0];
	for (int i = 1; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
}

template <typename T, typename U>
static inline std::vector<U> makeNdVector(T n, U val) noexcept {
	return std::vector<U>(std::forward<T>(n), std::forward<U>(val));
}

template <typename T, typename ...Args>
static inline decltype(auto) makeNdVector(T n, Args... args) noexcept {
	return std::vector<decltype(makeNdVector(std::forward<Args>(args)...))>(std::forward<T>(n), makeNdVector(std::forward<Args>(args)...));
}

std::int64_t gcd(std::int64_t x, std::int64_t y) {
	if (x == 0 || y == 0) return 0;
	std::int64_t r;
	while ((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}

std::int64_t lcm(std::int64_t x, std::int64_t y) {
	if (x == 0 || y == 0) return 0;
	return (x / gcd(x, y) * y);
}

std::int64_t mod(std::int64_t a, std::int64_t m) {
	return (a % m + m) % m;
}

void insertionSort(vint& A) {
	rep(i, A.size()) {
		int v = A[i];
		int k = i - 1;
		while (k >= 0 && A[k] > v) {
			A[k + 1] = A[k];
			k--;
		}
		A[k + 1] = v;
		print(A);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//using P = pair<i64, int>;

	int N; cin >> N;
	vint A(N);
	rep(i, N) cin >> A[i];
	
	insertionSort(A);
}

