#include <stdio.h>

int sort(const void* a, const void* b) {
  return *( int * )a - *( int * )b;
}

int main(void) {
    	int i,j,k,n,q,t;
	int S[100000];
	int T[50000];
	int R[500];
	
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &S[i]);
	}

	scanf("%d\n", &q);
	for(i=0;i<q;i++) {
		scanf("%d", &T[i]);
	}
	
	qsort((void*)S, n, sizeof(S[0]), sort);
	qsort((void*)T, q, sizeof(T[0]), sort);
	
	i=j=k=0;
	while(i<n&&j<q) {
		if(S[i] == T[j]) {
			R[k] = S[i];
			i++;j++;k++;
		} else if(S[i] > T[j]) {
			j++;
		} else if(S[i] < T[j]) {
			i++;
		}
	}
	printf("%d\n", k);

	return 0;
}
