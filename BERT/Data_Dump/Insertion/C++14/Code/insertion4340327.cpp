#include <iostream>
#include "bits/stdc++.h"
using namespace std;
using graph = vector<vector<int>>;
typedef long long ll;


int main() {
	ll n,mem,j;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	for (ll i = 0; i < n; i++) {
		mem = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > mem) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = mem;
		for (ll k = 0; k < n; k++) {
			cout << array[k];
			if (k + 1 < n) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
