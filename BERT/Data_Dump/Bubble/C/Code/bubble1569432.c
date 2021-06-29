#include <stdio.h>

int bubbleSort(int *a, int n);
void swap(int *a, int *b);

int main(void)
{
	int i;
	int n;
	int ans;
	int a[100];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	ans = bubbleSort(a, n);
	for (i = 0; i < n - 1; i++) printf("%d ", a[i]);
	printf("%d\n%d\n", a[i], ans);
	
	return (0);
}

int bubbleSort(int *a, int n)
{
	int i;
	int count;
	int flag;
	
	flag = 1;
	count = 0;
	while (flag){
		flag = 0;
		for (i = n - 1; i >= 1; i--){
			if (a[i] < a[i - 1]){
				swap(&a[i], &a[i - 1]);
				flag = 1;
				count++;
			}
		}
	}
	
	return (count);
}

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a, *a = *b, *b = tmp;
}
