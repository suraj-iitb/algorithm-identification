#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
using namespace std;



int main() {
	int n;
	cin >> n;
	int count = 0;
	vector<int> a(n);
	int v;
	for (int i = 0; i < n;i++) {
		cin >> a.at(i);
	}
	for (int i = 1;i< n;i++) {
		for (int j = i;j >= 1;j--) {
			if (a.at(j) < a.at(j-1)) {
				v = a.at(j);
				a.at(j) = a.at(j-1);
				a.at(j-1) = v;
				count++;
			}
		}
	}
	for (int i = 0; i < n;i++) {
		cout << a[i];
		if (i < n-1)cout << " ";
		else cout << endl;
	}
	cout << count << endl;
}

