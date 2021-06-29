#include <stdio.h>

#define MAX 100

void change(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int selectionSort(int a[], int n)
{
	int i,j;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		int minj = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		if (minj != i) {
			change(&a[i], &a[minj]);
			cnt++;
		}
	}
	return cnt;
}
void print_a(int a[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%d ", a[i]);
		
	}
	printf("%d\n", a[n - 1]);
}
int main()
{
	int a[MAX], n,i,cnt;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	cnt = selectionSort(a, n);
	print_a(a, n);
	printf("%d\n", cnt);
	return 0;

}
