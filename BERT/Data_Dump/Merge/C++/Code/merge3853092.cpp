#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <stdio.h>
#include <vector>
#define INFTY = 2000000000;
using namespace std;
typedef long long int ll;
 vector<ll> L(250002), R(250002);
 ll cut;
void merge(ll A[], ll left, ll mid, ll right) {
	ll n1 = mid - left, n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L.at(i) = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R.at(i) = A[mid + i];
	}
	L[n1] = R[n2] = 2000000000;
	ll i = 0, j = 0;
	for (ll k = left; k < right; k++) {
		cut++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}
void MergeSort(ll A[], ll N, ll left, ll right) {
	if (left + 1 < right) {
		ll mid = (left + right) / 2;
		MergeSort(A, N, left, mid);
		MergeSort(A, N, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	ll N; cin >> N;
	cut = 0;
	ll A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	MergeSort(A, N, 0, N);
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1) cout << ' ';
	}
	cout << endl << cut << endl;

}
