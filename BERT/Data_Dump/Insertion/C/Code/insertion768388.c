#include <stdio.h>

void FuncShowArray(int array[], int head, int num)
{
  int i;
  for (i = head; i <= num; i++){
	  if (i > head) putchar(' ');
      printf("%d", array[i]);
  }
  putchar('\n');
}


int main(void)
{
	int a[1024];
	int n;
	int key;
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	FuncShowArray(a, 1, n);
	for (i = 2; i <= n; i++) {
		key = a[i];

		/* insert a[i] into the sorted sequence a[1,...,i-1] */
		for (j = i - 1; j > 0 && a[j] > key; j--)
			a[j+1] = a[j];
		a[j+1] = key;

		FuncShowArray(a, 1, n);
	}

	return 0;
}
