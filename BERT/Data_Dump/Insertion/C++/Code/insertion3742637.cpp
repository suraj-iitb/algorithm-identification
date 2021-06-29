#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> A(n);
	for (ll i = 0; i < n; i++)cin >> A[i];
	for (ll i = 0; i < n-1; i++) {
		cout << A[i] << ' ';
	}
	cout << A[n - 1] << endl;
	for (ll i = 1; i < n; i++) {
		ll v = A[i];
		ll j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (ll p = 0; p < n-1; p++) {
			cout << A[p] << ' ';
		}
		cout << A[n - 1] << endl;
	}
}
