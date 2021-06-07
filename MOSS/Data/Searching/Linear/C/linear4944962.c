#include <stdio.h>
#include <stdlib.h>

int find_element(int a[], int n, int element) {
	int i;
	for (i=0; i<n; i++) {
		if (a[i] == element) {
			return 1;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	
	int a[20000], b[10000];
	int a_n,b_n;
	int i,j,k=0;
	
	scanf("%d", &a_n);
	for (i=0; i<a_n; i++) {
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &b_n);
	for (i=0; i<b_n; i++) {
		scanf("%d", &b[i]);
	}
	
	for (i=0; i<b_n; i++) {
		if (find_element(a, a_n, b[i]) == 1) {
			k++;
		}
	}	
	
	printf("%d\n", k);
	
	
	return 0;
}
