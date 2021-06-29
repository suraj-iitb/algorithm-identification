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
#include <climits>

using namespace std;
int c = 0;
void merge(vector<int>& orig, int l, int mid, int r) {
	int nl = mid - l;
	int nr = r - mid;
	vector<int> left(nl+1), right(nr+1);
	for (size_t i = 0; i < nl; i++)
	{
		left[i] = orig[l+i];
	}
	for (size_t i = 0; i < nr; i++)
	{
		right[i] = orig[mid+i];
	}
	left[nl] = INT_MAX;
	right[nr] = INT_MAX;

	int i = 0, j = 0;
	for (size_t k = 0; k < nl+nr; k++)
	{
		c++;
		if(left[i] < right[j]) {
			orig[l+k] = left[i];
			i++;
		} else {
			orig[l+k] = right[j];
			j++;
		}
	}
}



void mergesort(vector<int>& a, int l, int r) {
	if(l+1 >= r) return;
	
	int mid = (l+r)/2;
	mergesort(a, l, mid);
	mergesort(a, mid, r);
	merge(a, l, mid ,r);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(a, 0, n);
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

