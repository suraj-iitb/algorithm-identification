#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n;
int a[2000001];


void countsort()
{
	int b[10002] = {0};
	for (int i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	int count = 0;
	for (int i = 0; i < 10002; i++)
	{
		while (b[i] >0)
		{
			if (count) {
				printf(" ");
			}
			count++;
			printf("%d", i);
			b[i]--;
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	countsort();

	return 0;

}
