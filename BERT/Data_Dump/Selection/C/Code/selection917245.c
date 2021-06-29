#include<stdio.h>

void swap(int *a,int *b){
	int t;
	t=*b;
	*b=*a;
	*a=t;
}

int main(){
	int n, i, j, A[100], count = 0,mini;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < n - 1; i++){
		mini = i;
		for (j = i; j <= n - 1; j++){
			if (A[j] < A[mini]){
				mini = j;
			}
		}
		if (A[i] != A[mini]){
			swap(&A[i], &A[mini]);
			count++;
		}
	}

	for (i = 0; i < n; i++){
		printf("%d", A[i]);
		if (i < n - 1){ printf(" "); }
	}
	printf("\n%d\n",count);

	return 0;
}
