#include<stdio.h>

int n;
int a[10000000];

int binarySearch(int key)
{
	int min = 0;
	int max = n;
	int mid;
	while(min < max)
	{
		mid = (min + max) / 2;
		if(key == a[mid]) return 1;
		if(key > a[mid])
		{
			min = mid + 1;
		}
		else if(key < a[mid])
		{
			max = mid;
		}
	}
	return 0;
}
int main(void)
{
	int i, q, key;
	int c = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &q);
			
	for(i = 0; i < q; i++)
	{
		scanf("%d", &key);
		if(binarySearch(key)) c++;
	}
	printf("%d\n", c);
	return 0;
}
