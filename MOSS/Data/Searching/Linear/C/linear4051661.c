#include <stdio.h>

int main(void) {
	int n,q;
	int seq[10000],set[500];
	int i,j,k;
	int count;

	// read sequence
	scanf("%d",&n);
	for (i = 0;i != n;++i) {
		scanf("%d",seq + i);
	}
	// read set
	scanf("%d",&q);
	for (i = 0;i != q;++i) {
		scanf("%d",set + i);
	}
	// linear search
	for (i = 0;i != n;++i) {
		j = 0;
		while (j != q) {
			if (seq[i] == set[j]) {
				++count;
				// delete this element in set
				for (k = j + 1;k != q;++k) {
					set[k - 1] = set[k];
				}
				--q;
			} else {
				++j;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
