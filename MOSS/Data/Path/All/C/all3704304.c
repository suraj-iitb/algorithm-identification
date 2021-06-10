#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

constexpr Int INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int v, e; cin >> v >> e;
	vector<vector<Int>> a(v, vector<Int>(v, INF));
	for(Int i=0; i<e; ++i){
		Int s, t, d; cin >> s >> t >> d;
		a[s][t] = d;
	}
	for(Int i=0; i<v; ++i)
		a[i][i] = 0;
	for(Int k=0; k<v; ++k)
		for(Int i=0; i<v; ++i)
			for(Int j=0; j<v; ++j)
				a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
	for(Int i=0; i<v; ++i)
		if(a[i][i] < 0){
			cout << "NEGATIVE CYCLE\n";
			return 0;
		}
	for(Int i=0; i<v; ++i)
		for(Int j=0; j<v; ++j)
			cout << (a[i][j] > INF / 2 ? "INF" : to_string(a[i][j])) << " \n"[j+1==v];
}
