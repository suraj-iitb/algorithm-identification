#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int swapcount = 0;
	
	cin >> N;

	vector<int> A(N);

	for (int i = 0;i < N;i++)
		cin >> A[i];

	bool flag = true;

	while (flag)
	{
		flag = false;

		for (int i = N - 1;i >= 1;i--)
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
				swapcount++;
				flag = true;
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		if (i > 0)
			cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << swapcount << endl;

	return 0;
}
