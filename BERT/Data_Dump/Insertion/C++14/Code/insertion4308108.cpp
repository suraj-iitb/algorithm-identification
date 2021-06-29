#include	<bits/stdc++.h>
#define	rep(i, n) for (int i = 0; i < (n); ++i)
using	namespace std;
using	ll = long long;
using	P = pair<int, int>;

int main() {
	int			n;
	vector<int> A;

	cin >> n;
	rep(i, n)
	{
		int	x;
		cin >> x;
		A.push_back(x);
	}
	rep(i, n)
	{
		if (i)
			cout << ' ';
		cout << A.at(i);
	}
	cout << endl;
	for (int i = 1; i < n; i++)
	{
		int	j;
		int	v;

		v = A.at(i);
		j = i - 1;
		while (j >= 0 && A.at(j) > v)
		{
			A.at(j + 1) = A.at(j);
			j--;
		}
		A.at(j + 1) = v;
		rep(i, n)
		{
			if (i)
				cout << ' ';
			cout << A.at(i);
		}
		cout << endl;
	}
}

