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
	int n,count=0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < n; i++) {
		int min=v[i],zi=i;
		for (int j = i; j < n; j++) {
			if (min > v[j]) {
				min = v[j];
				zi = j;
			}
		}
		if (v[i] > v[zi]) {
			int swap;
			swap = v[i];
			v[i] = v[zi];
			v[zi] = swap;
			count++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != n - 1)cout << v[i] << " ";
		else cout << v[i] << endl;
	}
	cout << count << endl;
	return 0;
}
