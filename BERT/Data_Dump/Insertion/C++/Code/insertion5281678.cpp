#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
void insertion_sort(vector<int>& a, int i) {
	int w = 0;
	while (a[w] < a[i]) w++;
	int ii = a[i];
	for (int k = i - 1; k >= w; k--) a[k + 1] = a[k];
	a[w] = ii;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		insertion_sort(a, i);
		for (int j = 0; j < n; j++) {
			cout << a[j];
			if (j < n - 1) cout << " ";
			else cout << endl;
		}
	}
}
