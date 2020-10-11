#include<stdio.h>

int main(void){
	int i, j, n;
	scanf("%d", &n);
	int a[200000];
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int minj, tmp;
	int cnt = 0;

	for(i = 0;i<=n-1;i++){
		minj = i;
		for(j = i;j<=n-1;j++){
			if(a[j]<a[minj]){
				minj = j;
			}
		}
		tmp = a[i];
		a[i] = a[minj];
		a[minj] = tmp;
		if(minj != i)
			cnt++;
	}
	for(i = 0;i<n-1;i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
	printf("%d\n", cnt);
	return 0;
}
