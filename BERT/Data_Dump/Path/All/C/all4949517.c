#include "bits/stdc++.h"
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
const int MAX = 700000;
const int MOD = 1000000007;

long long  fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
/*逆元計算*/
long long int  modinv(long long a, long long m) {
	long long int b = m, u = 1, v = 0;
	while (b) {
		long long int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

//セグメントツリー(あってるかはわからんから自己責任で)
const int MAX_N = 10000000;
//セグメント木を持つグローバル配列
int n,dat[2*MAX_N - 1];

//初期化
void init(int n_){
	//簡単のため，要素数を２のべき乗に
	n = 1;
	while(n < n_) {
		n *= 2;
	}
	//すべての値をINT_MAXに
	for(int i = 0; i < 2 * n - 1; i++){
		//dat[i] = INT_MAX;
		dat[i] = 0;
	}
}
// k番目の値(0-indexed)をaに変更
void update(int k,int a){
	//葉の節点
	k += n - 1;
	dat[k] = a;
	//登りながら更新
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}
//　[a, b)の最小値を求める
//　後ろのほうの引数は，計算の簡単のための引数
//	kは節点の番号, l, rはその節点が[l, r)に対応づいていることを表す．
//　したがって，外からはquery(a, b, 0, 0, n)として呼ぶ．
int query(int a, int b, int k = 0, int l = 0, int r = n){
	// [a, b)と[l, r)が交差しなければ，INT_MAX
	if (r <= a || b <= l){ 
		return 0;
	}
	// [a, b)が[l, r)を完全に含んでいれば，この節点の値
	if (a <= l && r <= b){ 
		return dat[k];
	}else{
		//そうでなければ，2つの子の最小値
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl,vr);
	}
}

//Union-Find　アッカーマン関数よくわからない
int par[MAX_N];     //親
int ranks[MAX_N];    //木の深さ

//n要素で初期化
void initunion(int n){
    for(int i = 0;i < n;i++){
		par[i] = i;
    	ranks[i] = 0;
	}
}

//木の根を求める
int find(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}
//xとyの属する集合を併合
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    }
    if(ranks[x] < ranks[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(ranks[x] == ranks[y]){
            ranks[x]++;
        }
    }
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x) == find(y);
}

//めぐる式二部探索！サノバウィッチやったことない
// index が条件を満たすかどうか
vector<long long int >meguru;	
// index が条件を満たすかどうか
bool isOK(int index, int key) {
	if (meguru[index] >= key) return true;
	else return false;
}
// 汎用的な二分探索のテンプレ
int binary_search(int key) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = (int)meguru.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key)) right = mid;
		else left = mid;
	}
	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
long long int inf = 100000000000000;
long long int Graph[200][200] = {};
int main() {
	int v,e;
	cin >> v >> e;
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			Graph[i][j] = inf;
			if(i == j){
				Graph[i][j] = 0;
			}
		}
	}
	for(int i = 0;i < e;i++){
		long long int a,b,c;
		cin >> a >> b >> c;
		Graph[a][b] = c;
	}
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			for(int k = 0;k < v;k++){
				if(Graph[j][i] != inf && Graph[i][k] != inf){
					Graph[j][k] = min(Graph[j][k],Graph[j][i]+Graph[i][k]);
				}
			}
		}
	}
	for(int i = 0;i < v;i++){
		if(Graph[i][i] < 0){
			cout <<"NEGATIVE CYCLE"<<endl;
			return 0;
		}
	}
	for(int i = 0;i < v;i++){
		for(int j = 0;j < v;j++){
			if(Graph[i][j] == inf){
				cout <<"INF"; 
			}else{
				cout <<Graph[i][j];
			}
			if(j != v-1){
				cout <<" ";
			}
		}
		cout <<endl;
	}
}

