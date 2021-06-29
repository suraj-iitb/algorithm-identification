#include<stdio.h>

int main(void){
	int i, j, n, max;
	scanf("%d", &n);
	int a[200000];
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int flag =1;
	int cnt = 0, tmp;

	while(flag){
		flag =0;
		for(j=n-1;j>=1;j--){
			if(a[j]<a[j-1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				cnt++;
				flag = 1;
			}
		}
	}
	for(i = 0;i<n-1;i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
	printf("%d\n", cnt);
	return 0;
}
