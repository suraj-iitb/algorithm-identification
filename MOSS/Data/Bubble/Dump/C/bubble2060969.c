#include<stdio.h>
int main()
{
    int N;
	int A[100];
	int i;
    scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int j;
	int flag = 1;
	int tmp;
	int count = 0;
	while(flag) {
		flag = 0;
		for(j = N - 1; j > 0; j--) {
			if(A[j] < A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	for(i = 0; i < N - 1; i++) {
		printf("%d",A[i]);
		printf(" ");
	}
	//printf("%d\n%d", A[N-1], count);
printf("%d\n",A[N-1]);
printf("%d\n", count);
			
    return 0;
}
