#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
#define SENTINEL (1LL << 33)

ll Merge(vector<ll> &A, ll left, ll	mid, ll right) {
	ll n1 = mid - left;
	ll n2 = right - mid;
	vector<ll> L(n1+1,0), R(n2+1,0);
	// left, ..., mid-1
	for(ll i=0; i<n1; ++i){
		L[i] = A[left+i];
	}
	// mid, ..., right-1
	for(ll i=0; i<n2; ++i){
		R[i] = A[mid+i];
	}
	L[n1] = SENTINEL; 
	R[n2] = SENTINEL; 
	ll i, j;
	i = j = 0;
	for (ll k=left; k<right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
	return (right - left);
}

ll MergeSort(vector<ll> &A, ll left, ll right) {
	ll count = 0;
	if (left+1 < right) {
		ll mid = (left + right)/2;
		count += MergeSort(A,left,mid);
		count += MergeSort(A,mid,right);
		count += Merge(A, left, mid, right);
	}
	return count;
}

void print(const vector<ll> &A) {
	for(ll i=0;i<A.size(); ++i){
		if(i!=0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> A(n,0);
	for (ll i=0;i<n;++i) scanf("%lld", &A[i]);
	ll count = MergeSort(A, 0, n);
	print(A);
	cout << count << endl;
	return 0;
}	

