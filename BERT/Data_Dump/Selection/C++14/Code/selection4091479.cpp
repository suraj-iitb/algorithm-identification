#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, cnt = 0;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i);
	}

	for (int i = 0; i < N - 1; i++)
	{
		int minj = i;
		for (int j = i; j < N; j++)
		{
			if (A.at(j) < A.at(minj))
			{
				minj = j;
			}
		}
		if (minj != i)
		{
			swap(A.at(i), A.at(minj));
			cnt++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
			cout << A.at(i) << ' ';
		else
			cout << A.at(i) << endl;
	}
	cout << cnt << endl;
}
