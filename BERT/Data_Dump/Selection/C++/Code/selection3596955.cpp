#include<iostream>
#include<vector>
using namespace std;

int selectionsort(vector<int>& v, int n) {
	int count = 0;
	for (int i = 0; i < n - 1; ++i) {
		int minv =i;
		for (int j = i+1; j < n; ++j) {
			if (v[minv] > v[j]) {
				minv = j;
			}
		}
		if (minv != i)++count;
		swap(v[i],v[minv]);
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)cin >> v[i];
	int ans = selectionsort(v, n);
	for (int i = 0; i < n; ++i) {
		if (i)cout << " ";
		cout << v[i];
	}
	cout << endl;
	cout << ans << endl;
	return 0;
}

