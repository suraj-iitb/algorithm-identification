#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>

using namespace std;
int c = 0;

// void bubblesort(vector<int>& a, int n) {
// 	int flag = 1;
// 	while(flag) {
// 		flag = 0;
// 		for (int i = n - 1; i >= 1; i--)
// 		{
// 			if(a[i-1] > a[i]) {
// 				swap(a[i-1], a[i]);
// 				c++;
// 				flag = 1;
// 			}
// 		}
// 	}
// }

void bubblesort(vector<int>& a, int n) {
	for (int j = 0; j < n; j++)
	{
		for (int i = n-1; i > j; i--)
		{
			if(a[i-1] > a[i]) {
				swap(a[i-1], a[i]);
				c++;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bubblesort(a, n);
	for (size_t i = 0; i < n; i++)
	{
		if(i == 0) {
			cout << a[i];
			continue;
		}
		cout << " " << a[i];
	}
	cout << endl;
	cout << c << endl;
}

