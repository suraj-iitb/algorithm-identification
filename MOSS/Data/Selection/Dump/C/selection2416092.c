#include<stdio.h>

void araisanSort(int a[], int len) {

	int min=0 , temp;
	int i, j, cou = 0;
	for (i = 0; i < len; i++)
	{
		min = i;
		for (j = i + 1;j < len;j++) {
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i) {
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
			cou++;
		}
		
	}
	for (i = 0;i < len - 1;i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n%d\n", a[i], cou);
}
int main() {
		int n;
		int i;
		int ar[100];
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &ar[i]);
		}
		araisanSort(ar, n);
	return 0;
}
