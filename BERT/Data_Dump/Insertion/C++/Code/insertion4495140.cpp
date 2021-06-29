#include <bits/stdc++.h>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;
 
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];
	rep(i, n)
		cin >> a[i];

	rep(k, n) {
		if (k > 0) cout << ' ';
		cout << a[k];
	}
	cout << endl;

	int tmp;
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		
		rep(k, n) {
			if (k > 0) cout << ' ';
			cout << a[k];
		}
		cout << endl;
	}
}
