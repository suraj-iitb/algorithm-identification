#include <bits/stdc++.h>
#define	rep(i, n) for (int i = 0; i < (n); ++i)
using	namespace std;
using	ll = long long;
using	P = pair<int, int>;

int	selection_sort(vector<int> &A, int n)
{
	int		sw;
	bool	flag;

	flag = true;
	sw = 0;
	for (int i = 0; flag; i++)
	{
		int	j;

		j = n - 1;
		flag = false;
		while (j > i)
		{
			if (A.at(j) < A.at(j - 1))
			{
				swap(A.at(j), A.at(j - 1));
				flag = true;
				sw++;
			}
			j--;
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

