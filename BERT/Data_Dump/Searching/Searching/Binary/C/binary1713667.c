#include<stdio.h>
int n, s[100000];
int binary_search(int t)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (t == s[mid]) {
			return 1;
		}
		else if (t < s[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}

int main()
{
	int q, t[50000],i,c=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
		
	}
	for (i = 0; i < q; i++) {
		if (binary_search(t[i]) == 1) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
