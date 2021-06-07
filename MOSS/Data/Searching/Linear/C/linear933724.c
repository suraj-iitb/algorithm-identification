#include <stdio.h>

int int_sort(const void* a, const void* b) {
  return *( int * )a - *( int * )b;
}

int main(void) {
	int T[10000];
	int S[500];
	int R[500];
	int i,j,k,n,q,t;
	
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &T[i]);
	}

	scanf("%d\n", &q);
	for(i=0;i<q;i++) {
		scanf("%d", &S[i]);
	}
	
	qsort((void*)T, n, sizeof(T[0]), int_sort);
	qsort((void*)S, q, sizeof(S[0]), int_sort);
	
	i=j=k=0;
	while(i<n&&j<q) {
		if(T[i] == S[j]) {
			R[k] = T[i];
			i++;j++;k++;
		} else if(T[i] > S[j]) {
			j++;
		} else if(T[i] < S[j]) {
			i++;
		}
	}
	printf("%d\n", k);

	return 0;
}
