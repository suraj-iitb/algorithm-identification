#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i);
		if (i != N - 1)
		{
			cout << A.at(i) << ' ';
		}
		else
		{
			cout << A.at(i) << endl;
		}
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (A.at(j) > A.at(j + 1))
			{
				swap(A.at(j), A.at(j + 1));
			}
			else
			{
				break;
			}
		}
		for (int j = 0; j < N - 1; j++)
		{
			cout << A.at(j) << ' ';
		}
		cout << A.at(N - 1) << endl;
	}
}
