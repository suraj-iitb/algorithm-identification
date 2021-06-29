#include <stdio.h>
const SIZE = 100;
int main(){
	int N, i, v, j, k;
	int a[SIZE];
	scanf("%d", &N);
	for(i = 0; i < N; i ++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N; i ++){
		if(i != N - 1){
			printf("%d ", a[i]);
		}else{
			printf("%d\n", a[i]);
		}
	}
	for(i = 1; i < N; i ++){
		v = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j --;
			a[j + 1] = v;
		}
		for(k = 0; k < N; k ++){
			if(k != N - 1){
				printf("%d ", a[k]);
			}else{
				printf("%d\n", a[k]);
			}
		}
	}
	return 0;
}
