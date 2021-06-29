#include <cstdio>
using namespace std;

//每次排序后打印结果
void trace(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");

}

//插入排序函数
void insertiomSort(int A[], int N)
{
//将所有变量声明在循环之外可以减少运行时间，加快速度
	int min = A[0];
	for (int i = 1; i < N; i++)
	{
		min = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > min)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = min;
		trace(A, N);
	}
}

int main()
{
	int A[100],i,j,N;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	trace(A, N);
	insertiomSort(A, N);

	return 0;
}
