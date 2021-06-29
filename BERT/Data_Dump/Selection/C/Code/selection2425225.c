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
	int min_i;
	int swap_count = 0;

	scanf("%d",&n);
	for (i = 0;i < n;++i) {
		scanf("%d",seq + i);
	}
	// selection sort
	for (i = 0;i < n - 1;++i) {
		min_i = i;
		for (j = i + 1;j < n;++j) {
			if (seq[j] < seq[min_i]) {
				min_i = j;
			}
		}
		if (i != min_i) {
			swap(seq + i,seq + min_i);
			++swap_count;
		}
	}
	for (i = 0;i < n;++i) {
		printf("%d",seq[i]);
		printf(i == n - 1 ? "\n" : " ");
	}
	printf("%d\n",swap_count);
	return 0;
}
