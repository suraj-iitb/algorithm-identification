#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

int ans;

void mergeSort(vector<int>::iterator a, vector<int>::iterator b) {
	if (1 + a < b) {
		ans += b - a;
		mergeSort(a, next(a, (b - a) / 2));
		mergeSort(next(a, (b - a) / 2), b);
		queue<int> c, d;
		for (vector<int>::iterator i = a; i != next(a, (b - a) / 2); ++i) c.push(*i);
		c.push(INT_MAX);
		for (vector<int>::iterator i = next(a, (b - a) / 2); i != b; ++i) d.push(*i);
		d.push(INT_MAX);
		for (vector<int>::iterator i = a; i != b; ++i) {
			if (c.front() < d.front()) {
				*i = c.front();
				c.pop();
			}
			else {
				*i = d.front();
				d.pop();
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> S(n);
	for (int& i : S) cin >> i;
	mergeSort(S.begin(), S.end());
	for (int i = 0; i < n - 1; ++i) cout << S[i] << ' ';
	cout << S.back() << endl << ans << endl;
}
