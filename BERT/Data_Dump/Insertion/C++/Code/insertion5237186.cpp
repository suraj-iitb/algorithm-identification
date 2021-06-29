#include <iostream>
using namespace std;

int main()
{
	int n;
	int A[100];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int j = 0; j < n; j++)
	{
		cout << (j == 0 ? "" : " ") << A[j];
	}
	cout << endl;
	int v;
	int j;
	for (int i = 1; i < n; ++i) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (j = 0; j < n; j++)
		{
			cout << (j == 0 ? "" : " ") << A[j];
		}
		cout << endl;
	}
	return 0;
}

