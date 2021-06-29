#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INFTY = 1e11;
ll ans;

void merge(ll a[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;

	ll l[n1+1];
	rep(i,n1+1) l[i] = a[left+i];

	ll r[n2+1];
	rep(i,n2+1) r[i] = a[mid+i];

	l[n1] = INFTY;
	r[n2] = INFTY;

	int i,j;
	i = j = 0;

	FOR(k,left,right){
		ans++;
		if(l[i] <= r[j]){
			a[k] = l[i];
			i++;
		}else{
			a[k] = r[j];
			j++;
		}
	}
}


void mergeSort(ll a[], int left, int right){
	if(left+1 < right){
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	ll a[n];
	rep(i,n) cin >> a[i];

	ans = 0;

	mergeSort(a,0,n);
	rep(i,n) cout << a[i] << (i == n-1 ? "\n" :" "); 
	cout << ans << endl;
}
