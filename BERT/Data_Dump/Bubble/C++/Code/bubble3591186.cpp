#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<utility>
#define repp(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define repm(i,a,b) for(int i=(int)a;i>(int)b;--i)
//using ll=long long;
//static const ll mod = 1e9;
//static const ll INF = 1LL << 50;
using namespace std;

int num = 0;

void bubblesort(vector<int>& v, int n) {//参照渡ししないと反映されない
	for (int i = 0; i < n - 1; ++i) {
		for (int j =0; j < n-1; ++j) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
				++num;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	repp(i, 0, n)cin >> v[i];
	bubblesort(v, n);
	repp(i, 0, n) {
		if (i)cout << " ";
		cout << v[i];
	}cout << endl;
	cout << num << endl;
	return 0;
}
