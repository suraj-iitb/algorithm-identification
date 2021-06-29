#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

void Print(const vector<int>& a)
{
	for (int i = 0; i < a.size() - 1; i++) cout << a[i] << " ";
	cout << a.back() << endl;
}

void InsertionSort(vector<int>& a)
{
	int n = a.size();
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i;
		for (; 0 < j; j--) {
			if (v < a[j - 1]) a[j] = a[j - 1];
			else break;
		}
		a[j] = v;
		Print(a);
	}
}


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	Print(a);
	InsertionSort(a);
}

