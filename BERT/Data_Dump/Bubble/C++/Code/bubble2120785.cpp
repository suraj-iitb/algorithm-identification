
#include <iostream>
#include <stdio.h>
using namespace std;

static const int MAX_COUNT = 100;
static int R[MAX_COUNT];



int BubleSort(int* A, int n)
{
	int cnt = 0;
	int flg = 1;
	int tmp;

	while (flg)
	{
		flg = 0;

		for (int i = n - 1; i > 0; i--)
		{
			if (*(A + i - 1) > *(A + i))
			{
				tmp = *(A + i);
				*(A + i) = *(A + i - 1);
				*(A + i - 1) = tmp;
				flg = 1;
				cnt++;
			}
		}
	}

	return cnt;
}


int main()
{
	int n;
	int i;
	int ret;


	cin >> n;

	if (n > MAX_COUNT)
		return -1;

	for (i = 0; i < n; i++)
	{
		cin >> R[i];
	}


	ret = BubleSort(R, n);


	for (i = 0; i < n-1; i++)
	{
		printf("%d ", R[i]);
	}
	printf("%d\n%d\n", R[i], ret);

	return 0;
}
