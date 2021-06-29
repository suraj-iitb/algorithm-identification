#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100

int n;
int A[100100];

int main() {
	cin >> n;
	rep(i, n)cin >> A[i];
	bool flag = true;
	int cnt = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				cnt++;
				flag = true;
			}
		}
	}
	rep(i, n) {
		if (i == 0)cout << A[i];
		else cout << " " << A[i];
	}
	cout << endl;
	cout << cnt << endl;
}
