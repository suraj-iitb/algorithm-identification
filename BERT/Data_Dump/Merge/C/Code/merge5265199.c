#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int a[500005];
int n;
int count = 0;

void mcom(int b[], int head,int mid, int tail)
{
	int mer_l = head;
	int mer_r = mid + 1;
	int wei = head;
	while (mer_l <= mid && mer_r <= tail)
	{
		if (a[mer_l] < a[mer_r]){
			b[wei++] = a[mer_l++];
			count++;
		}
		else {
			b[wei++] = a[mer_r++];
			count++;
		}
	}

	while (mer_l <= mid)
	{
		b[wei++] = a[mer_l++];
		count++;
	}

	while (mer_r <= tail)
	{
		b[wei++] = a[mer_r++];
		count++;
	}

	while (head<= tail)
	{
		a[head] = b[head];
		head++;
	}
}


void mergesort(int b[], int head, int tail)
{
	if (head < tail)
	{
		int mid = (head + tail) / 2;
		mergesort(b, head, mid);
		mergesort(b, mid+1, tail);
		mcom(b,head, mid, tail);
	}
}


void merge()
{
	int* b = (int*)malloc(sizeof(int) * n);
	if (b)
	{
		mergesort(b, 0, n - 1);
	}
	free(b);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	merge();
	for (int i = 0; i < n; i++)
	{
		if (i != 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n%d\n", count);
	return 0;
}
