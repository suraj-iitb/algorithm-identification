#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

void Show(int ary[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != 0) cout << " ";
		cout << ary[i];
	}

	cout << endl;
}

int* InsertionSort(int ary[], int n)
{
	for (int i = 1; i < n; i++)
	{
		Show(ary, n);

		int buf = ary[i];
		int j = i - 1;
		while (j >= 0 && ary[j] > buf) {
			ary[j + 1] = ary[j];
			j--;
			ary[j + 1] = buf;
		}
	}

	Show(ary, n);

	return ary;
}

int main()
{
	int n;
	int ary[100];

	cin >> n;

	for (int i = 0; i < n; i++) cin >> ary[i];

	InsertionSort(ary, n);

	return 0;
}

