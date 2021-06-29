#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int n, v, j;
	cin >> n;
	vector<int>A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i != n - 1)
			cout << " ";
		else
			cout << endl;
	}

	for (int i = 1; i < n; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int k = 0; k < n; k++) {
			cout << A[k];
			if (k != n - 1)
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}
