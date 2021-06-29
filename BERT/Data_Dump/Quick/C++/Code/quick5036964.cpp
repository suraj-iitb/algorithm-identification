#include<cstdio>
int partition(int *A, char *B, int p, int r);
void quicksort(int *A, char *B, int p, int r);
int judgestable(int *A, char *B, int *C, char *D, int n);
int main()
{
	int n;
	scanf("%d", &n);
	int A[n],C[n];
	char B[n], D[n];
	getchar();
	for(int i = 0; i < n; i++){
		B[i] = getchar();
		scanf("%d", A+i);
		getchar();
	}
	for(int i = 0; i < n; i++){
		C[i] = A[i];
		D[i] = B[i];
	}
	quicksort(C, D, 0, n - 1);
	if(judgestable(A, B, C, D, n))
		printf("Stable\n");
	else 
		printf("Not stable\n");
	for(int i = 0; i < n; i++)
		printf("%c %d\n", D[i], C[i]);
	return 0;
}
int partition(int *A, char *B, int p, int r)
{
	char c;
	int x = A[r], i = p - 1, j, temp;
	for( j = p; j <= r - 1; j++){
		if(A[j] <= x){
			++i;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			c = B[j];
			B[j] = B[i];
			B[i] = c;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	c = B[i + 1];
	B[i + 1] = B[r];
	B[r] = c;
	return i + 1;
}
void quicksort(int *A, char *B, int p, int r)
{
	int q;
	if(p < r){
		q = partition(A, B, p, r);
		quicksort(A, B, p, q - 1);
		quicksort(A, B, q + 1, r);
	}
}
int judgestable(int *A, char *B, int *C, char *D, int n)
{
	int j, k;
	for(int i = 0; i <= n - 1; i++){
		if(i && C[i] == C[i - 1]){
			for(j = 0;A[j] != C[i - 1] || B[j] != D[i - 1]; j++);
			for(k = j + 1; (A[k] != C[i] || B[k] != D[i]) && k < n; k++);
			if(k == n)
				return 0;
		}
	}
	return 1;
}
