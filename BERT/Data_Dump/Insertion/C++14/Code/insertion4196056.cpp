#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int j = 0; j < n; ++j) {
		cout << (j == 0 ? "" : " ") << v[j];
	}cout << endl;
	for (int i = 1; i <n; ++i) {
		int k = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > k) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = k;
		for (int j = 0; j < n; ++j) {
			cout << (j == 0 ?"" : " ") << v[j];
		}cout << endl;
	}

	return 0;
}
