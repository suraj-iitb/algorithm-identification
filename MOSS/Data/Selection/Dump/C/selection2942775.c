#include<stdio.h>
int main(void){
	int n, last, a[100], i, j, min_ind, tmp, cnt = 0;
	
	scanf("%d\n", &n);
	last = n-1;
	for(i = 0; i < n; i++){
		if(i == last){
			scanf("%d\n", &a[i]);
			break;
		}
		scanf("%d ", &a[i]);
	}
	for(i = 0; i < last; i++){
		min_ind = i;
		for(j = i+1; j < n; j++){
			if(a[min_ind] > a[j]){
				min_ind = j;
			}
		}
		if(min_ind != i){
			tmp = a[i];
			a[i] = a[min_ind];
			a[min_ind] = tmp;
			cnt++;
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
