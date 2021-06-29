#include <bits/stdc++.h>
#define int long long
#define ll long long 
#define rep(i,a,b) for(signed i=a;i<(b);++i)
#define erep(i,a,b) for(signed i=a;i<=(b);++i)
#define per(i,a,b) for(signed i=(a);i>(b);--i)
#define eper(i,a,b) for(signed i=(a);i>=b;--i)
#define fore(i, x, a) for(auto &&x:a) 
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define pb emplace_back
#define mp make_pair
#define ALL(x) begin(x),end(x)
#define F first
#define S second
#define debug(x)  cout << #x << ": " << (x) << '\n';
const long long INF=1001001001001001001;
const int MOD=(int)1e9 + 7;
const double EPS=1e-9;
using namespace std;
using Pii = pair<int,int>;
using vii = vector<int>;
template<class T>using  PS_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){fill( (T*)array, (T*)(array+N), val );}
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> ostream& operator<<(ostream &os,const vector<vector<T>> &v) {
    ITR(u,begin(v),end(v))ITR(w,begin(*u),end(*u))os<<*w<<(w==end(*u)-1?"\n":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct edge { int from, to, cost; };
int dy[]={0, 1, -1, 0}; int dx[]={1, 0, 0, -1};
// cout << fixed;
// cout << setprecision(10) << val;

int cnt;

void mergeSort(int* a, int left, int right) {
	if (right - left <= 1)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid, right);

	int n1 = mid - left, n2 = right - mid;
	int L[n1+1], R[n2+1];
	for (int i = 0; i < n1; i++) 
		L[i] = a[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[mid + i];
	L[n1] = INF, R[n2] = INF;

	int itr_x = 0, itr_y = 0;
	for (int i = left; i < right; i++) {
		if (L[itr_x] <= R[itr_y]) 
			a[i] = L[itr_x++];
		else
			a[i] = R[itr_y++];
		cnt++;
	}
}

int n, a[500001];
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	mergeSort(a, 0, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << (i != n-1 ? " " : "\n");
	}
	cout << cnt << endl;
  return 0;
}


