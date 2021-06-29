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
void selectionsort(vector<int>& a, int n) {
	for (size_t i = 0; i < n; i++)
	{
		int ind = i;
		for (size_t j = i; j < n; j++)
		{
			if(a[ind] > a[j]) {
				ind = j;
			}
		}
		if(a[i] != a[ind]) {
			c++;
			swap(a[i], a[ind]);
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
	selectionsort(a, n);
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

