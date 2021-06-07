#include<stdio.h>

int main(){
	int i, j, k, S[100000], T[50000], n, q, c = 0, right, left, mid;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}
	
	for (i = 0; i < q; i++) {
		right = n - 1;
		left = 0;
		mid = (left + right) / 2;
		while (right != mid && left != mid) {
			if (S[mid] > T[i]) {
				right = mid;
				mid = (left + right) / 2;
			}
			else if (S[mid] < T[i]) {
				left = mid;
				mid = (left + right) / 2;
			}
			else {
				left = mid;
				right = mid;
			}
		}
		if (T[i] == S[left] || T[i] == S[mid] || T[i] == S[right]) {
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}

