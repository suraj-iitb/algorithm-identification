#include <cstdio>
const int MAXN = 110;

using namespace std;

int selectionSort(int A[], int N);

int main()
{
	int n;
	scanf("%d", &n);

	int nums[MAXN];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}

	int sw = selectionSort(nums, n);

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			printf("%d ", nums[i]);
		}
		else
		{
			printf("%d", nums[i]);
		}
	}
	printf("\n%d\n", sw);

	return 0;
}

int selectionSort(int A[], int N)
{
	int temp;
	int sw = 0;

	for (int i = 0; i < N; i++)
	{
		int minj = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;
		if (minj != i)
		{
			sw++;
		}
	}

	return sw;
}
