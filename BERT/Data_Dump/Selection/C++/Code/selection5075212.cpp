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

ll selectionSort(ll A[], ll N) {
	ll sw = 0;
	ll minj;
	for (ll i = 0; i < N - 1; i++) {
		minj = i;
		for (ll j = i; j < N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		swap(A[i], A[minj]);
		if (i != minj) sw++;
	}
	return sw;
}

int main() {
	ll N;
	cin >> N;
	ll A[110];
	rep(i, N) cin >> A[i];
	ll sw = selectionSort(A, N);
	for (ll i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}
