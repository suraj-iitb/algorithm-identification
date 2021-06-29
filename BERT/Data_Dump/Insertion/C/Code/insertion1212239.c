#include<stdio.h>

static const int N = 1000;

void print(int *a, int n){
	int i;

	for(i = 0; i < n; i++){
		printf("%d", a[i]);
		if(i < n - 1)
			printf(" ");
	}
	puts("");

}

void sort(int *a, int n){
	int i, j, key;
	print(a, n);
	for(i = 1; i < n; i++){
		key = a[i];
		j = i - 1;

		while(a[j] > key  && j >= 0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		print(a, n);
	}
}

int main(){
	int n, i;
	int A[N+1];

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, n);
	return 0;

}
