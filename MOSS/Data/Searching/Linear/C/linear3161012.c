#include <stdio.h>

int A[10001],n;
int list_accord(int key)
{
	int i;
	int flag = 0;
	for (i = 0; i < n; i++) {
		if (A[i] == key) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	int i, m, temp;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &temp);
		sum += list_accord(temp);
	}
	printf("%d\n", sum);

	return 0;
}

