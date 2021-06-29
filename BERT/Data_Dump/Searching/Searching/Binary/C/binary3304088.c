#include<stdio.h>
int search(int *,int,int);
int main() {
	int a[100000], b[100000], an, bn,i,j,num,key,ans = 0;
	scanf("%d", &an);
	num = 0;
	for ( i = 0; i < an ; i++)
	{
		scanf("%d", &key);
		if (i > 0 && a[i - 1 - num] == key)
		{
			num++;
		}
		else
		{
			a[i - num] = key;
		}
	}
	an -= num;
	scanf("%d", &bn);
	for ( i = 0; i < bn; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < bn; i++)
	{
		ans += search(a, an, b[i]);
	}
	printf("%d", ans);
	printf("\n");
	
	return 0;
}
int search(int *x,int right, int y) {
	int left =0, mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (x[mid] == y)
		{
			return 1;
		}
		else
		{
			if (x[mid] > y)
			{
				right = mid;
			}
			else
			{
				if (x[mid] < y)
				{
					left = mid + 1;
				}
			}
		}
	}
	return 0;
}
