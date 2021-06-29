#include <bits/stdc++.h>
#define	rep(i, n) for (int i = 0; i < (n); ++i)
using	namespace std;
using	ll = long long;
using	P = pair<int, int>;

int	selection_sort(vector<int> &A, int n)
{
	int		sw;

	sw = 0;
	rep(i, n - 1)
	{
		int		minj;

		minj = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A.at(j) < A.at(minj))
				minj = j;
		}
		if (minj != i)
		{
			swap(A.at(i), A.at(minj));
			sw++;
		}
	}
	return (sw);
}

int main() {
	int	n;
	cin >> n;

	vector<int>	A(n);
	rep(i, n)
		cin >> A.at(i);

	int	sw;

	sw = selection_sort(A, n);
	rep(i, n)
	{
		if (i)
			cout << ' ';
		cout << A.at(i);
	}
	cout << endl;
	cout << sw << endl;
}

