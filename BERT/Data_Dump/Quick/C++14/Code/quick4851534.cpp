#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
/*#include <atcoder/dsu>
using namespace atcoder;
//using mint = modint998244353;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion
const ll mod = 998244353;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

/*--------------------------------------------------------------------------------------------------------------------------------*/
struct card{
	char ch;
	int val;
	bool operator==(const card& c) const {
		return ch == c.ch && val == c.val;
	}
};

int partition(vector<card> &a, int l, int r){
	int i = l - 1;
	int x = a[r - 1].val;
	for(int j = l; j < r - 1; j++){
		if(a[j].val <= x){
			i++;
			card tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	card tmp = a[r - 1];
	a[r - 1] = a[++i];
	a[i] = tmp;
	return i;
}

void quick_sort(vector<card> &a, int l, int r){
	if(l < r){
		int x = partition(a, l, r);
		quick_sort(a, l, x); // x - 1までの範囲をやると良い
		quick_sort(a, x + 1, r); // x + 1からの範囲をやると良い
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<card> a(n);
	rep(i, n) cin >> a[i].ch >> a[i].val;
	vector<card> B(a);
	quick_sort(a, 0, n);
	stable_sort(B.begin(), B.end(), [](const card& c1, const card& c2) { return c1.val < c2.val; });
	cout << (a == B ? "Stable" : "Not stable") << endl;
	for(int i = 0; i < n; i++){
		cout << a[i].ch << " " << a[i].val << endl;
	}
}

