#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int insSrot(vector<int>& a) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		int minj = i;
		for (int j = i; j < a.size(); j++) {
			if (a[j] < a[minj]) minj = j;
		}
		if (i != minj) cnt++;
		swap(a[i], a[minj]);

	}
	for (int i  = 0; i < a.size(); i++) {
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


	cout << insSrot(a) << endl;

	return 0; 
}

