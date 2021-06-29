#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

#define REP(i,s,N) for(ll i=s;i<N;++i)

void print(const vector<ll> &x) {
	REP(i,0,x.size()) {
		if (i == 0) printf("%lld", x[i]);
		else printf(" %lld", x[i]);
	}
	cout << endl;
}

void sort(vector<ll> &x) {
	REP(i,0,x.size()) {
		ll j = i-1;
		ll key = x[i];
		while (j >= 0 && key < x[j]) {
			x[j+1] = x[j];
			--j;
		}
		x[j+1] = key;
		print(x);
	}
}

int main() {
	ll n;
	cin >> n;
	vector<ll> x(n,0);
	REP(i,0,n) scanf("%lld", &x[i]); 
	sort(x);
	return 0;
}


