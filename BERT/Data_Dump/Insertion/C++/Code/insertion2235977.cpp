#include <iostream>
#include <vector>

using namespace std;

void Output(vector<int> A)
{
	for (int i = 0;i < A.size();i++)
	{
		cout << A[i];
		if (i != A.size() - 1)
			cout << " ";
	}
	cout << endl;
}

int main()
{
	int N;

	cin >> N;

	vector<int> A(N);

	for (int i = 0;i < N;i++)
		cin >> A[i];

	Output(A);
	for (int i = 1;i < N;i++)
	{
		int v = A[i];

		int j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = v;

		Output(A);
	}


	return 0;
}
