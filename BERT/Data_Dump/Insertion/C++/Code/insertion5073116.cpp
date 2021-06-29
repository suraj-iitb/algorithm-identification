#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i,n) for (ll i = 1; i <= (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define fcout cout<<fixed<<setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;

void trace(ll A[],ll N) {
	ll i;
	rep(i, N) {
		if (i > 0) {
			cout<<" ";
		}
		cout << A[i];
	}
	cout << endl;
	return;
}

void insertionSort(ll A[], ll N) {
	for (ll i = 1; i < N; i++) {
		ll v = A[i];
		ll j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
	return;
}

int main() {
	ll N, A[110];
	cin >> N;
	rep(i, N) cin >> A[i];
	trace(A, N);
	insertionSort(A, N);
	return 0;
}
