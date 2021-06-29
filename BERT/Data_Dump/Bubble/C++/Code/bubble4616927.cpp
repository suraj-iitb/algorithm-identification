#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX_LEN 100

using namespace std;

int a[MAX_LEN];

void printArray(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", a[i]);
		if (i != len - 1) printf(" ");
	}
	printf("\n");
}

int main()
{
	int len;
	scanf("%d", &len);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
	}

	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		bool flag = true;
		for (int j = len - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp;
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				count++;
				flag = false;
			}
		}
		if (flag) break;
	}
		printArray(a, len);
	printf("%d\n", count);

}
