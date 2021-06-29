#include <cstdio>
const int MAXN = 100;

using namespace std;

int main()
{
	int nums[MAXN];
	int key;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < n; i++)
	{
		key = nums[i];
		int j;
		for (j = i - 1; j >= 0 && nums[j] > key; j--)
		{
			nums[j + 1] = nums[j];
		}
		nums[j + 1] = key;
		for (int k = 0; k < n; k++)
		{
			if (k != n - 1)
			{
				printf("%d ", nums[k]);
			}
			else
			{
				printf("%d", nums[k]);
			}
		}
		putchar('\n');
	}

	return 0;
}
