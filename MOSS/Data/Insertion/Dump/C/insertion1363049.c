#include <stdio.h>

void Sort(int *a, int n){
	int i, c;
	for(i = 1; n > i; i++){
		for(c = 0; n > c; c++){
			printf("%d", a[c]);
			if(n-1 > c) printf(" ");
		}
		printf("\n");
		int v = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
}
int main(void) {
	int n, i, a[1000] = {};
	scanf("%d", &n);
	for(i = 0; n > i; i++){
		scanf("%d", &a[i]);
	}
	Sort(a, n);
		for(i = 0; n > i; i++){
			printf("%d", a[i]);
			if(n-1 > i) printf(" ");
		}
		printf("\n");
	return 0;
}
