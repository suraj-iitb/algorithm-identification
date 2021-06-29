#include <stdio.h>

int  Sort(int n, int *a){
	int f = 1, i, cou = 0;
	
	while(f){
		f = 0;
		for(i = 0; n-1 > i; i++){
			if(a[i] > a[i+1]){
				int buf = a[i+1];
				a[i+1] = a[i];
				a[i] = buf;
				f = 1;
				cou++;
			}
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
