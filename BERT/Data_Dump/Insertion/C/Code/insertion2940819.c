#include<stdio.h>
int main(void){
	int n, a[100], v, i, j, k, last;
	
	scanf("%d\n", &n);
	last = n-1;
	for(k = 0; k < n; k++){
		if(k == last){
			scanf("%d\n", &a[k]);
			break;
		}
		scanf("%d ", &a[k]);
	}
	for(k = 0; k < n; k++){
		if(k == last){
			printf("%d\n", a[k]);
			break;
		}
		printf("%d ", a[k]);
	}
	for(i = 1; i < n; i++){
		v = a[i];
		j = i - 1;
		while(a[j] > v && j >= 0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		for(k = 0; k < n; k++){
			if(k == last){
				printf("%d\n", a[k]);
				break;
			}
			printf("%d ", a[k]);
		}
	}
	
	return 0;
}
