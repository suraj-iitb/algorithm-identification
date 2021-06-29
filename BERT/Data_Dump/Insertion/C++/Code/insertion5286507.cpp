#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(x) x.begin(),x.end()

void printVec(vector<int> &a, int n) {
	for (int i = 0; i < n; i++) {
		if (i == 0) cout << a[i];
		else cout << " " << a[i];
	}
	cout << endl;
}

void insertionSort(vector<int> &a, int n) {
	for(int i = 1; i < n; i++) {
		printVec(a, n);
		int v = a[i];
		int j = i - 1;
		while (j >= 0 and a[j] > v) {
			a[j+1] = a[j];
			j -= 1;
		}
		a[j+1] = v;
	}
}

int main(){
	//cout << fixed << setprecision(10);
	int n; cin >> n;
	vector<int> a(n);
	rep (i, n) cin >> a[i];

	insertionSort(a, n);

	printVec(a, n);
	return 0;
}

