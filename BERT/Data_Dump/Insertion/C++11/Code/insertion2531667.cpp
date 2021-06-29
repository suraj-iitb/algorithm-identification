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
	int n;
	cin >> n;
	vector<int> vv(n);
	for (int i = 0; i < n; i++) {
		cin >> vv[i];
		if(i!=n-1)cout << vv[i] << " ";
		else cout << vv[i] << endl;
	}
	for (int i = 1; i < n; i++) {
		int v, j;
		v = vv[i];
		j = i - 1;
		while (j >= 0 && vv[j] > v) {
			vv[j + 1] = vv[j];
			j--;
			vv[j + 1] = v;
		}
		//vv[j + 1] = v;
		
		
		for (int k = 0; k < n; k++) {
			if(k!=n-1)cout << vv[k] << " ";
			else cout << vv[k] << endl;
		}
	}

	return 0;
}
