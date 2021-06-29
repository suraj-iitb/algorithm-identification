#include <iostream>
#include <stdio.h>
using namespace std;
static const int MAX_COUNT = 100;

int main()
{
	int n;
	int R[MAX_COUNT];


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}

	int v;
	int j;

	for (int k = 0; k < n - 1; k++)
	{
		printf("%d ", R[k]);
	}
	printf("%d\n", R[n - 1]);


	for (int i = 1; i < n; i++)
	{
		v = R[i];
		j = i - 1;

		while (j >= 0 && R[j] >= v)
		{
			R[j+1] = R[j];
			j--;
		}
		R[j + 1] = v;

		for (int k = 0; k < n-1; k++)
		{
			printf("%d ", R[k]);
		}
		printf("%d\n", R[n-1]);

	}

	cin.ignore();
	getchar();

	return 0;
}
