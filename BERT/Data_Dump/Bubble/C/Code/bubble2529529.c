#include <stdio.h>

int main(void) {
	int n;
	int i;
	int a[100] ={};
	int j;
	int tmp;
	int flag = 1;
	int count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (j = n - 1; j > 0; j --){
		if (flag == 0){
			break;
		}
		flag = 0;
		for (i = 0; i < j; i++){
			if (a[i] > a[i+1]){
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				flag = 1;
				count++;
			}
			
		}
	}
	for (i = 0; i < n - 1; i++){
		printf("%d ", a[i]);
	}
	printf("%d", a[n-1]);
	printf("\n");
	printf("%d\n", count);
	return 0;
}
