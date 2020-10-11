#include <stdio.h>

#define MAX 100

void change(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int bubbledSort(int a[], int n)
{
	int flag = 1;
	int j;
	int cnt = 0;
	while (flag) {
		flag = 0;
		for (j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				change(&a[j], &a[j - 1]);
				cnt++;
				flag = 1;
			}
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

	cnt = bubbledSort(a, n);
	print_a(a, n);
	printf("%d\n", cnt);
	return 0;

}
