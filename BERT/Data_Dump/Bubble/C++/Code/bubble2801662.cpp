#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;++i)
int cnt = 0;
void mysort(vector<int>&a) {
	int n = a.size();
	rep(i, n - 1)
	{
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j-1],a[j]);
				cnt++;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	mysort(a);
	rep(i, n) {
		if (i != 0) { cout << " "; }
		cout << a[i];
	}
	cout << endl << cnt<< endl;
	return 0;
}
