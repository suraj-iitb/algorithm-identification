#include<stdio.h>

void sort(int n, int *a, int *cnt){
	int i, j, min, tmp;

	for(i = 0; i < n; i++){
		min = i;
		for(j = i; j < n; j++){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i){
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
			(*cnt)++;
		}
	}
}

void print(int n, int *a){
	int i;

	for(i=0; i < n; i++){
		printf("%d", a[i]);
		( i != n-1) ? printf(" ") : printf("\n");
	}
}

int main(){
	int i, j, n, cnt;
	int a[100];

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(n, a, &cnt);
	print(n, a);
	printf("%d\n", cnt);

	return 0;
}
