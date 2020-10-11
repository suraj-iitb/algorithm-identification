#include<stdio.h>
int main(void){
	int n, last, a[100], i, j, tmp, flag = 1, cnt = 0;
	
	scanf("%d\n", &n);
	last = n-1;
	for(i = 0; i < n; i++){
		if(i == last){
			scanf("%d\n", &a[i]);
			break;
		}
		scanf("%d ", &a[i]);
	}
	while(flag){
		flag = 0;
		for(j = last; j > 0; j--){
			if(a[j-1] > a[j]){
				tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
				flag = 1;
				cnt++;
			}
		}
	}
	for(i = 0; i < n; i++){
		if(i == last){
			printf("%d\n", a[i]);
			break;
		}
		printf("%d ", a[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
