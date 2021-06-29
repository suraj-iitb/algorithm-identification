#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, k;
	int n;
	int* a;
	scanf("%d", &n);
	a = malloc(sizeof(int)*n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 1; i < n; i++){
		printf("%d", a[0]);
		for(k = 1; k < n; k++)
			printf(" %d", a[k]);
		printf("\n");
		int v = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
	printf("%d", a[0]);
	for(k = 1; k < n; k++)
		printf(" %d", a[k]);
	printf("\n");
	return 0;
}
