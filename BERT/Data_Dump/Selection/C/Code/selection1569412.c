#include <stdio.h>

int selectionSort(int *a, int n);
void swap(int *a, int *b);

int main(void)
{
	int a[100];
	int n;
	int i;
	int ans;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	ans = selectionSort(a, n);
	for (i = 0; i < n - 1; i++) printf("%d ", a[i]);
	printf("%d\n%d\n", a[i], ans);
	
	return (0);
}

int selectionSort(int *a, int n)
{
	int i, j;
	int min ;
	int count = 0;
	
	for (i = 0; i < n; i++){
		min = i;
		for (j = i; j < n; j++){
			if (a[j] < a[min]) min = j;
		}
		if (i != min) swap(&a[i], &a[min]), count++;
	}
	
	return (count);
}

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a, *a = *b, *b = tmp;
}
