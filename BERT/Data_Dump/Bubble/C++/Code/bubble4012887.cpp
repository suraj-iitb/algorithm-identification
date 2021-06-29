#include <cstdio>
const int MAXN = 100;

using namespace std;

int bubbleSort(int A[], int N);

int main()
{
	int nums[MAXN];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}

	int sw = bubbleSort(nums, n);

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


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

int bubbleSort(int A[], int N)
{
	int sw = 0;
	int temp;
	
	bool flag = true;
	for (int i = 0; i < N - 1 && flag; i++)
	{
		flag = false;
		for (int j = N - 1; j > i; j--)
		{
			if (A[j] < A[j - 1])
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = true;
				sw++;
			}
		}
	}

	return sw;
}

