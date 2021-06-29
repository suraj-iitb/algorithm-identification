#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);

	int i, j, length, key, A[100];

	cin >> length;
	for (int i = 0; i < length; i++)	cin >> A[i];

	for (int i = 1; i < length; i++){
		cout << A[0];
		for (j = 1; j < length; j++)	cout << " " << A[j];
		cout << endl;

		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j]>key)
			A[j + 1] = A[j--];
		A[j + 1] = key;
	}
	cout << A[0];
	for (j = 1; j < length; j++)	cout << " " << A[j];
	cout << endl;
	return 0;
}
