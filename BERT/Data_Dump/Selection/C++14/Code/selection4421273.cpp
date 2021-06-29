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
	int a[100];
	int count=0;
	for (int i = 0; i < n;i++)cin >> a[i];
	for (int i = 0;i < n;i++) {
		int minj = i;
		for (int j = i;j < n;j++) {
			if (a[j] < a[minj]) minj = j;
		}
		if (a[i] != a[minj]) {
			swap(a[i], a[minj]);
			count++;
		}
	}
	for (int i = 0;i < n;i++) {
		cout << a[i];
		if (i < n - 1)cout << " ";
		else cout << endl;
	}
	cout << count << endl;
}

