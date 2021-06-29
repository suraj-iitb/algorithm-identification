#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
#include<iomanip>
#include<cassert>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;//要素数
	int v;
	int j;

	cin >> n;

	vector<int> a(n);
	rep(i, n){
		cin >> a[i];
		if (i != n - 1){
			cout << a[i] << ' ';
		}
		else{
			cout << a[i] << '\n';
		}
	}

	for (int i = 1; i < n; i++){//1からn-1まで
		v = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = v;

		rep(k, n){
			if (k != n - 1){
				cout << a[k] << ' ';
			}
			else{
				cout << a[k] << '\n';
			}
		}
	}

	return 0;
}
