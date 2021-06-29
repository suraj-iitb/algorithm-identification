#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[100]; for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
			else break;
		}
		cout << a[0];
		for (int k = 1; k < n; k++) cout << " " << a[k];
		cout << endl;
	}
	return 0;
}

