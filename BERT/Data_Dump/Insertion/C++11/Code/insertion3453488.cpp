#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void out(vector<int> ve, int size) {
	for (int i = 0; i < size-1; ++i)
	{
		cout << ve[i] << " ";
	}
	cout << ve[size-1] << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	out(a, n);

	for (int i = 1; i < n; ++i)
	{
		int v = a[i];
		int j = i-1;
		while (j >= 0 && a[j] > v)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		out(a, n);
	}

	return 0;
}
