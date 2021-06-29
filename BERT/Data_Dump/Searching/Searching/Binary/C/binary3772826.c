//二分搜索
#include<stdio.h>

int A[100000], n;

int binarySearch(int key)
{
	int left = 0;
	int right = n;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key == A[mid]) return 1;//find key
		else if (key > A[mid]) left = mid + 1;//搜索后半部分
		else if (key < A[mid]) right = mid;//搜素后半截
	}
	return 0;//循环推出，未找到
}
int main()
{
	int i, q, key, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &key);
		if (binarySearch(key)) sum++;
	}
	printf("%d\n", sum);
	return 0;
}
