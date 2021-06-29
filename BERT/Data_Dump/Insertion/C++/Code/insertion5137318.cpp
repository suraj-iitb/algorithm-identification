#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAN_N 0x3f3f3f
int main(void)
{
	int a[105], i, n,x,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		x = a[i];
		for (j = i-1; j >= 0; j--)
		{
			if (x < a[j])
			{
				
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
	    }
		if (i != 0)
		{
			a[j + 1] = x;
		}
		for (int m= 0; m < n; m++)
		{
			if (m != n - 1)
			{
				printf("%d ", a[m]);
			}
			else printf("%d", a[m]);
		}
			printf("\n");
	}

	return 0;
}
