#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
typedef long long ll;
const int MAX_N=2000010;

int main(){
	//只能用C写 
	unsigned short *A, *B;
	int n,i,j;
	int C[10010];
	scanf("%d",&n);
	A = malloc(sizeof(short) * n + 1);
	B = malloc(sizeof(short) * n + 1);
	for(i=0;i<=10010;i++)
		C[i]=0;
	for(i=1;i<=n;i++){
		scanf("%hu",&A[i]);
		C[A[i]]++;
	}
	for(i=1;i<=10010;i++)
		C[i]=C[i]+C[i-1];
	for(j=1;j<=n;j++){
		B[C[A[j]]]=A[j];
		C[A[j]]--;
	}
	for(i=1;i<=n;i++){
		if(i>1)
			printf(" ");
		printf("%d",B[i]); 
	} 
	printf("\n");
	return 0;
}

/*
样例
7
2 5 1 3 2 3 0
输出
0 1 2 2 3 3 5
*/
