#include <stdio.h>

#define N_MAX 100
int count = 0;

void
print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%s", a[i], i + 1 < n ? " " : "");
	printf("\n");
}

int
bubble_sort(int *a, int n)
{
	int i, v, flag = 1;
	while (flag) {
		flag = 0;
		for (i = n - 1; i > 0;i--) {
			if (a[i] < a[i - 1]) {
				v = a[i];
				a[i] = a[i - 1];
				a[i - 1] = v;
				flag = 1;
				count++;
			}
		}
	}
}

int main(void)
{
	int p0, i, n = 0;
	int a[N_MAX];
	char *p;

	scanf("%d", &p0);

	if (p0 < 1 || N_MAX < p0)
		return 1;

	while (n < p0)
		scanf("%d", a + n++);

	bubble_sort(a, n);
	print_array(a, n);
	printf("%d\n", count);

	return 0;
}

