#include <stdio.h>

int FuncBubbleSortInt(int a[], int len);
void FuncShowArray(int array[], int head, int num);

int main(void)
{
	int n, num[128];
	int count;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	count = FuncBubbleSortInt(num, n);
	FuncShowArray(num, 0, n);
	printf("%d\n", count);

	return 0;
}

int FuncBubbleSortInt(int a[], int len)
{
	int count = 0;
	int temp;
	int i, j;

	for (i = 0; i < len; i++) {
		for (j = (len - 1); j > i; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				count++;
			}
		}
	}

	return (count);
}

void FuncShowArray(int array[], int head, int num)
{
  int i;

  for (i = head; i < num; i++){
	  if (i > head) putchar(' ');
      printf("%d", array[i]);
  }
  putchar('\n');
}
