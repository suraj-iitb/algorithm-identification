#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);++(i))
#define rREP(i,m,n) for(int (i)=(n)-1;(i)>=(m);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 1000000001;
constexpr ll mod = 1000000007;
constexpr double PI = 3.1415926535897932;

template<class T>inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void init() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}


int main() {
	init();

	int N; cin >> N;
	vector<int>vec(N);
	rep(i, 0, N)cin >> vec[i];
	rep(i, 0, N) {
		cout << vec[i];
		if (i == N - 1)cout << "\n";
		else cout << " ";
	}
	rep(i, 1, N) {
		int v = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > v) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = v;
		rep(i, 0, N) {
			cout << vec[i];
			if (i == N - 1)cout << "\n";
			else cout << " ";
		}
	}

	return 0;
}
