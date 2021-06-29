#include<stdio.h>

void print_a(int n, int *a)
{
	int i;
	for(i=0;i<n-1;i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
}

int main(void)
{
	int n, a[100], i, j, v;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	print_a(n, a);
	for(i=1;i<n;i++) {
		v = a[i];
		j = i-1;
		while(j >= 0 && a[j] > v) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		print_a(n, a);
	}
	return 0;
}
