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

	for (int i = 0;i < N;i++)
	{
		int minj = i;

		for (int j = i;j < N;j++)
		{
			if (A[j] < A[minj])
				minj = j;
		}

		swap(A[i], A[minj]);
		if (i != minj)
			swapcount++;
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
