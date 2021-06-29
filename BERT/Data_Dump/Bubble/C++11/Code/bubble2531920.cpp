#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string.h>
#include <deque>
#define REP(i,j,n) for(int i=j;i<n;i++)
#define SORT(x) sort(x.begin(),x.end())

using namespace std;

int main() {
	int n, count = 0;
	bool flag = true;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (flag) {
		flag = false;
		for (int i = n - 1; i > 0; i--) {

			if (v[i - 1] > v[i]) {
				int swap;
				swap = v[i - 1];
				v[i - 1] = v[i];
				v[i] = swap;
				count++;
				flag = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != n - 1)cout << v[i] << " ";
		else cout << v[i] << endl;
	}
	cout << count << endl;
	return 0;
}
