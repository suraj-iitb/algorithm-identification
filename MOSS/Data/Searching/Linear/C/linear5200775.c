#include<stdio.h>
int main()
{
	int a[10001],m,n,b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int e = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &b);
		for (int j = 0; j < n; j++) {
			if (b == a[j]) {
				e++;
				break;
			}
		}
	}
	printf("%d\n", e);
	return 0;
}
