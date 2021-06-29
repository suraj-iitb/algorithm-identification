#include <stdio.h>

void FuncShowArray(int array[], int head, int tail);
void FuncSwapInt(int *a, int *b);
int FuncSelectionSortInt(int a[], const int len);

int main(void)
{
	int n, num[128];
	int count;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	count = FuncSelectionSortInt(num, n);
	FuncShowArray(num, 0, n);
	printf("%d\n", count);

	return 0;
}

int FuncSelectionSortInt(int a[], const int len)
{
	int count = 0;
	int mini;
	int flag = 0;
	int temp;
	int i, j;

	for (i = 0; i < len; i++) {
		mini = i;

		flag = 0;
		for (j = i; j < len; j++) {
			if (a[j] < a[mini]) {
				mini = j;
				flag = 1;
			}
		}
		
		FuncSwapInt(&a[i], &a[mini]);

		if (flag == 1) count++;
	}

	return (count);
}

void FuncSwapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void FuncShowArray(int array[], int head, int tail)
{
	int i;
	
	for (i = head; i < tail; i++){
	  if (i > head) putchar(' ');
      printf("%d", array[i]);
	}
	putchar('\n');
}
