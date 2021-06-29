
#include <stdio.h>

int N;
int A[1000];

int insertion(int a[], int b);
int print(int d[], int c);

int main(){

	int i = 0;
   
	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	print(A, N);
	insertion(A, N);



}

int insertion(int a[], int b){
	int v;
	int i;
	int j;
	for (i = 1; i <= N - 1; i++){
		v = A[i];
		j = i - 1;
	 
		while (j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		print(A,b);

	}

	return 0;

}

int print(int d[], int c){
	int i = 0;
	for (i = 0; i < c; i++){
		if (i > 0) printf(" ");
		printf("%d", d[i]);
	}
	printf("\n");
	return 0;
}
