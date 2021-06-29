#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
using namespace std;
typedef  long long int lint;
typedef pair<int, int> IP;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
const lint MOD = pow(10, 9) + 7;

int main() {
	int N;
	cin >> N;
	deque<int>A;
	int a = 0;
	rep(i, N) {
		cin >> a;
		A.push_back(a);
	}
	vector<int>V;
	rep(i, N) {
		a = A.front();
		A.pop_front();
		V.push_back(a);
		sort(V);
		rep(i, V.size()) {
			cout << V[i];
			if (i != N - 1) {
				cout << ' ';
			}
		}
		rep(i, A.size()) {
			cout << A[i];
			if (i != A.size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
