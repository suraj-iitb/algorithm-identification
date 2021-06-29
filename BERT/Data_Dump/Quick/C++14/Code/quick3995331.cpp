#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool isprime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int mypow(int a, int b) {
	if (!b)return 1;
	if (b % 2)return mypow(a, b - 1) * a;
	int memo = mypow(a, b / 2);
	return memo * memo;
}
int modpow(int a, int b, int m = mod) {
	if (!b)return 1;
	if (b % 2)return modpow(a, b - 1, m) * a % m;
	int memo = modpow(a, b / 2, m);
	return memo * memo % m;
}
class UnionFind {
	int* par, * rank;
	P* notparent;
	vector<P>* size;
	int opcount = 0;
public:
	UnionFind(unsigned int size) {
		par = new int[size + 1];
		rank = new int[size + 1];
		this->size = new vector<P>[size + 1];
		notparent = new P[size + 1];
		rep(i, size + 1) {
			par[i] = i;
			rank[i] = 0;
			this->size[i].push_back(make_pair(-1, 1));
			notparent[i] = make_pair(INF, i);
		}
	}
	int find(int n, int t = INF) {
		if (opcount <= t) {
			if (par[n] == n)return n;
			return par[n] = find(par[n]);
		}
		if (notparent[n].first <= t)return find(notparent[n].second, t);
		return n;
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) {
			opcount++;
			return;
		}
		if (rank[n] < rank[m]) {
			par[n] = m;
			notparent[n] = make_pair(opcount, m);
			size[m].push_back(make_pair(opcount, size[m].back().second + size[n].back().second));
		}
		else {
			par[m] = n;
			notparent[m] = make_pair(opcount, n);
			size[n].push_back(make_pair(opcount, size[n].back().second + size[m].back().second));
			if (rank[n] == rank[m])rank[n]++;
		}
		opcount++;
	}
	bool same(int n, int m, int t = INF) {
		return find(n, t) == find(m, t);
	}
	int getsize(int n, int t = INF) {
		n = find(n, t);
		auto ite = lower_bound(size[n].begin(), size[n].end(), make_pair(t, (ll)0));
		if (ite == size[n].end())ite--;
		if (t < (*ite).first)ite--;
		return (*ite).second;
	}
};
class RollingHash {
	string s;
	int n, m, base;
	int* has;
	int mypow(int x, int y) {
		if (!y)return 1;
		if (y % 2)return this->mypow(x, y - 1) * x % m;
		int memo = this->mypow(x, y / 2);
		return memo * memo % m;
	}
public:
	RollingHash(string s, int m, int b) : n(s.size()), m(m), base(b) { init(s, m, b); }
	~RollingHash() { delete[] has; }
	void init(string s, int m, int b) {
		n = s.size();
		has = new int[n];
		base = b;
		this->s = s;
		this->m = m;
		rep(i, n) {
			has[i] = (int)s[i];
			if (i)has[i] += base * has[i - 1] % m;
			has[i] %= m;
		}
	}
	int query(int a, int b) {
		assert(!(a >= b || a < 0 || n < b));
		return (has[b - 1] - this->mypow(base, b - a) * (!a ? 0 : has[a - 1]) % m + m) % m;
	}
};
template<typename T, typename U>
class SegTree {
	int n = 1;
	T* node = NULL;
	U* lazy = NULL;
	bool* lazyflag = NULL;
	T nodee;
	U lazye;
	function<T(T, T)> nodef;
	function<U(U, U)> lazyf;
	function<T(int, T, U)> updf;
	void eval(int k, int l, int r) {
		if (lazyflag[k]) {
			node[k] = updf(r - l, node[k], lazy[k]);
			if (r - l > 1) {
				lazyflag[2 * k + 1] = lazyflag[2 * k + 2] = true;
				lazy[2 * k + 1] = lazyf(lazy[2 * k + 1], lazy[k]);
				lazy[2 * k + 2] = lazyf(lazy[2 * k + 2], lazy[k]);
			}
			lazyflag[k] = false;
			lazy[k] = lazye;
		}
	}
public:
	SegTree(int m, int init, T nodee, U lazye, function<T(T, T)> nodef, function<U(U, U)> lazyf, function<T(int, T, U)> updf) :nodee(nodee), lazye(lazye), nodef(nodef), lazyf(lazyf), updf(updf) {
		delete[] node;
		delete[] lazy;
		while (n < m)n *= 2;
		node = new T[2 * n], lazy = new U[2 * n], lazyflag = new bool[2 * n];
		rep(i, 2 * n) {
			node[i] = init;
			lazy[i] = lazye;
			lazyflag[i] = false;
		}
	}
	~SegTree() {
		delete[] node;
		delete[] lazy;
	}
	void update(int a, int b, U x, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (b <= l || r <= a)return;
		if (a <= l && r <= b) {
			lazyflag[k] = true;
			lazy[k] = x;
			eval(k, l, r);
		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = nodef(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (b <= l || r <= a)return nodee;
		if (a <= l && r <= b)return node[k];
		T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return nodef(vl, vr);
	}
};
class Matrix {
	int n;
	vector<vector<int>> vec;
	void Measure() {
		rep(i, n) {
			rep(j, n) {
				if (i != j)vec[i][j] = 0;
				else vec[i][j] = 1;
			}
		}
	}
public:
	Matrix(int n) {
		this->n = n;
		vec.resize(n, vector<int>(n));
	}
	Matrix(int n, vector<int> vec) {
		if (vec.size() != n * n) {
			cerr << "Invalid construct of matrix" << endl;
			exit(1);
		}
		this->n = n;
		this->vec.resize(n, vector<int>(n));
		rep(i, n) {
			rep(j, n)this->vec[i][j] = vec[i * n + j];
		}
	}
	int operator[](int a) {
		return vec[a / n][a % n];
	}
	unsigned int size() { return n; }
	Matrix operator*(const Matrix a) {
		if (this->n != a.n) {
			cerr << "Invalid maltiply of matrix" << endl;
			exit(1);
		}
		vector<int> memo(n);
		rep(i, n) {
			rep(j, n) {
				rep(k, n) {
					memo[j] += vec[i][k] * a.vec[k][j];
				}
			}
			vec[i] = memo;
			memo.clear();
			memo.resize(n);
		}
		return *this;
	}
	Matrix letmod(int m = mod) {
		rep(i, n) {
			rep(j, n)vec[i][j] %= m;
		}
		return *this;
	}
	static Matrix measure(int n) {
		Matrix res(n);
		res.Measure();
		return res;
	}
	static Matrix mypow(Matrix a, int b, int m = mod) {
		a.letmod(m);
		if (!b)return Matrix::measure(a.size());
		if (b % 2)return (mypow(a, b - 1, m) * a).letmod(m);
		Matrix memo = mypow(a, b / 2, m);
		return (memo * memo).letmod(m);
	}
};
class mycomplex {
	double realvalue, imagvalue;
public:
	mycomplex() :realvalue(0), imagvalue(0) {}
	mycomplex(double realvalue, double imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	mycomplex(double realvalue) : realvalue(realvalue), imagvalue(0) {}
	mycomplex(complex<double> c) :realvalue(c.real()), imagvalue(c.imag()) {}
	mycomplex(const mycomplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double real()const { return this->realvalue; }
	double imag()const { return this->imagvalue; }
	double abs() { return hypot(realvalue, imagvalue); }
	mycomplex& operator=(const mycomplex& obj) {
		if (this != &obj) {
			this->realvalue = obj.realvalue;
			this->imagvalue = obj.imagvalue;
		}
		return *this;
	}
	mycomplex& operator=(mycomplex&& obj)noexcept {
		if (this != &obj) {
			this->realvalue = exchange(obj.realvalue, 0);
			this->imagvalue = exchange(obj.imagvalue, 0);
		}
		return *this;
	}
	mycomplex& operator+=(const mycomplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	friend mycomplex operator+(mycomplex lhs, const mycomplex& rhs) {
		lhs += rhs;
		return lhs;
	}
	mycomplex& operator-=(const mycomplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	mycomplex& operator-=(const double& rhs) {
		this->realvalue -= rhs;
		return *this;
	}
	friend mycomplex operator-(mycomplex lhs, const mycomplex& rhs) {
		lhs -= rhs;
		return lhs;
	}
	mycomplex& operator*=(const mycomplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	friend mycomplex operator*(mycomplex lhs, const mycomplex& rhs) {
		lhs *= rhs;
		return lhs;
	}
	mycomplex& operator/=(const mycomplex& rhs) {
		*this *= mycomplex(rhs.real(), -rhs.imag());
		double dnm = rhs.real() * rhs.real() - rhs.imag() * rhs.imag();
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}
	friend mycomplex operator/(mycomplex lhs, const mycomplex& rhs) {
		lhs /= rhs;
		return lhs;
	}
};
class FastFourierTransform {
private:
	static void dft(vector<mycomplex>& func, int inverse) {
		int sz = func.size();
		if (sz == 1)return;
		vector<mycomplex> veca, vecb;
		rep(i, sz / 2) {
			veca.push_back(func[2 * i]);
			vecb.push_back(func[2 * i + 1]);
		}
		dft(veca, inverse); dft(vecb, inverse);
		mycomplex now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
		rep(i, sz) {
			func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
			now *= zeta;
		}
	}
public:
	template<typename T>
	static vector<double> multiply(vector<T> f, vector<T> g) {
		vector<mycomplex> nf, ng;
		int sz = 1;
		while (sz < f.size() + g.size())sz *= 2;
		nf.resize(sz); ng.resize(sz);
		rep(i, f.size()) {
			nf[i] = f[i];
			ng[i] = g[i];
		}
		dft(nf, 1);
		dft(ng, 1);
		rep(i, sz)nf[i] *= ng[i];
		dft(nf, -1);
		vector<double> res;
		rep(i, sz)res.push_back(nf[i].real() / sz);
		return res;
	}
};
int n;
pair<int, char> a[100010], b[100010];
bool func(pair<int, char> x, pair<int,char> y) {
	return x.first < y.first;
}
int partition(int p, int r) {
	pair<int, char> x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j].first <= x.first) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void quicksort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i].second >> a[i].first;
		b[i] = a[i];
	}
	quicksort(0, n - 1);
	stable_sort(b, b + n, func);
	rep(i, n) {
		if (a[i] != b[i]) {
			puts("Not stable");
			goto kaage;
		}
	}
	puts("Stable");
kaage:;
	rep(i, n)cout << a[i].second << " " << a[i].first << endl;
	return 0;
}
