#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int bubbleSort(vector<int>& a) {
	int n = a.size();
	int cnt = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				cnt++;
				flag = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!i) cout << a[i];
		else cout << " " << a[i];
	}
	cout << endl;
	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << bubbleSort(a) << endl;
	return 0; 
}

