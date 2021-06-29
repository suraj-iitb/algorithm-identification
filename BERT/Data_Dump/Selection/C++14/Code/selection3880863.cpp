#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
#include <climits>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}
ll ketasum(ll n) { //桁の数字全ての和を返す 例: 112 -> 4
	ll sum=0;
	if (n<0) return 0;
	while (n>0) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

typedef pair<ll, ll> pair_t;

bool comp(const pair_t &a, const pair_t &b) {
        return a.first < b.first;
}

void sort2vectors(vector<ll> &av, vector<ll> &bv)
{ // ふたつの配列をまとめてそーと A[2,1] B[3,4] -> 1,4 2,3
        ll n = av.size();
        vector<pair_t> p(n);
        vector<ll> av2(n), bv2(n);
        for (ll i = 0; i < n; i++)
                p[i] = make_pair(av[i], bv[i]);
        sort(p.begin(), p.end(), comp);
        for (ll i = 0; i < n; i++) {
                av2[i] = p[i].first;
                bv2[i] = p[i].second;
        }
        av = av2;
        bv = bv2;
}
ll facctorialMethod(ll k){ //階乗
	ll s;
	if(k > 1){
		s = k*facctorialMethod(k-1);
	} else {
		s = 1;
	}
	return s;
}
vl primes(ll n){
	vl x(n);
	REP(i, n){
		x[i] = 0;
	}
	for(ll i = 2; i < sqrt(n) + 2; i++){
		while(n % i == 0){
			n /= i;
			x[i-1] += 1;
		}
	}
	if(n > 1){
		x[n-1] += 1;
	}
	return x;
}
const ll mod = 1000000007;
const ll INF = 1<<29;

// 変数定義start(vectorはresizeしようね)
ll N;
vl A;
// 変数定義end

void solve(){
	cin >> N;
	A.resize(N);
	REP(i, N){
		cin >> A[i];
	}
	ll count = 0;
	ll mini;
	for(ll i = 0; i < N; i++){
		mini = i;
		for(ll j = i; j < N; j++){
			if(A[j] < A[mini]){
				mini = j;
			}
		}
		swap(A[i], A[mini]);
		if(i != mini){
			count++;
		}
	}
	REP(i, N){
		if(i < N-1){
			cout << A[i] << " ";
		} else {
			cout << A[i] << endl;
		}
	}
	cout << count << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

