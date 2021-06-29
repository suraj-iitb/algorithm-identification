#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>


using ll = long long;
typedef std::pair<int, int>p;

ll min(ll a, ll b) {
	if (a >= b)return b;
	else return a;
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);

}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll Z = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
int d[210];
bool flag = true;
bool fl = true;
struct edge { int to, cost; };
std::vector<edge>v[100];
bool used[210];

int main() {
	int n, a[100], ans = 0;
	std::cin >> n;
	for (int i =0 ;i < n;i++){
		std::cin >> a[i];
	}
	while (flag) {
		for (int i = n - 1;i > 0;i--) {
			if (a[i] < a[i - 1]) {
				int b = a[i-1];
				a[i - 1] = a[i];
				a[i] = b;
				ans++;
			}
		}
		for (int i = 0;i < n;i++) {
			if (i == n - 1) {
				flag = false;
				break;
			}
			if (a[i] > a[i + 1]) {
				break;
			}
		}
	}
	for (int i = 0;i < n-1;i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << a[n - 1] << std::endl;
	std::cout << ans << std::endl;
	return 0;
}
