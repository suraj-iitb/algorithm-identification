#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int>v, int n) {
		for (int i = 0; i < n; ++i) {
			if (i)cout << " ";
			cout << v[i];
		}
		cout << endl;
	for (int i = 1; i < n; ++i) {//nが1なら条件式が偽になり、実行されない
		int m = v[i];
		for (int j = i-1; j>=0; --j) {
			if (v[j] > m) {
				v[j + 1] = v[j];
			}
			else if (v[j] <= m) {
				v[j + 1] = m;
				break;
			}
			if (j == 0)v[0] = m;
		}
		for (int i = 0; i < n; ++i) {
			if (i)cout << " ";
			cout << v[i];
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)cin >> v[i];
	insertionsort(v, n);
}
