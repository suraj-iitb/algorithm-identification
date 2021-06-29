#include <stdio.h>

void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int seq[100];
	int n;
	int i,j;
	int swap_count = 0;

	scanf("%d",&n);
	for (i = 0;i != n;++i) {
		scanf("%d",seq + i);
	}
	// bubble sort
	for (i = 0;i != n;++i) {
		for (j = n - 1;j != i;--j) {
			if (seq[j - 1] > seq[j]) {
				swap(seq + j,seq + j - 1);
				++swap_count;
			}
		}
	}
	for (i = 0;i < n;++i) {
		printf("%d",seq[i]);
		printf(i == n - 1 ? "\n" : " ");
	}
	printf("%d\n",swap_count);
	return 0;
}
