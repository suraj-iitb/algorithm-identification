#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001 // n????????§???
#define VMAX 10000 // ??????????????°???C[i]????????§?????°

int main(){
	unsigned short *A, *B; // 2????????????????????´??°

	int C[VMAX+1];
	int n, i, j;
	scanf("%d",&n);

	A = (unsigned short *)malloc(sizeof(short) * n + 1); // short?????????????????°*n+1??????????????°??????????????????????????????
	B = (unsigned short *)malloc(sizeof(short) * n + 1);

	for(i=0;i<=VMAX;i++) C[i] = 0; //?????????????????¢??°????????????

	for(i=0;i<n;i++){
		scanf("%hu",&A[i+1]); // 1?????????????????????
		C[A[i+1]]++; // ??????????????°???????????£????????\?????°????????????????????´??°???????????????????????°??????
	}

	for(i=1;i<=VMAX;i++) C[i] = C[i] + C[i-1]; // ??\?????°????????????i??\????????´??°???C[i]???????????????

	for(j=1;j<=n;j++){
		B[C[A[j]]] = A[j]; // ??\?????°???????????????A[j]???????°?????????´??°???C[A[j]]??????????????????????????§?????????????????????B[C[A[j]]]????????????A[j]?????\???
		C[A[j]]--; // A[j]??????????????????????????°???????????????
	}

	for(i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");

	return 0;
}
