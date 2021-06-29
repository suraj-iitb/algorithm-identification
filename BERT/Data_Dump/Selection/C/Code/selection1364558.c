#include <stdio.h>

int  Sort(int n, int *a){
	int f = 1, i, cou = 0, j = 0;
	
	for(j = 0; n-1 > j; j++){
		int minp, min = 101;
		for(i = j; n > i; i++){
			if(a[i] < min){
				min = a[i];
				minp = i;
			}
		}
		if(j != minp){
		int buf = a[j];
		a[j] = a[minp];
		a[minp] = buf;
		cou++;
		}
	}
	return cou;
}
int main(void) {
	int n, a[100], i;
	
	scanf("%d", &n);
	for(i = 0; n > i; i++){
		scanf("%d", &a[i]);
	}
	
	int cou = Sort(n, a);
	
	for(i = 0; n > i; i++){
		printf("%d", a[i]);
		if(n - 1 > i) printf(" ");
	}
	printf("\n%d\n", cou);
	return 0;
}
