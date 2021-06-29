#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n), b;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int t = 0;
		while(t < i && b[t] < a[i]) t++;
		// cout << t << "  ";
		b.push_back(a[i]);
		rotate(b.begin() + t, b.end() - 1, b.end());
		for(int j = 0; j <= i; j++) {
			cout << b[j] << (j == n - 1 ? "\n" : " ");
		}
		for(int j = i + 1; j < n; j++) {
			cout << a[j] << (j == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}
