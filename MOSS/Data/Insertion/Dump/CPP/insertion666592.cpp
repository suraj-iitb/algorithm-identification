#include <stdio.h>

int main(void){
	int i, j, k, n, a[100], tmp;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < n;i++){
		printf("%d",a[i]);
		if(i != n - 1) printf(" ");
	}
	printf("\n");
	for(i = 1;i < n;i++){
		tmp = a[i];
		for(j = i - 1;j >= 0 && a[j] > tmp;j--)
				a[j + 1] = a[j];
		a[j + 1] = tmp;
		for(j = 0;j < n;j++){
			printf("%d",a[j]);
			if(j != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
