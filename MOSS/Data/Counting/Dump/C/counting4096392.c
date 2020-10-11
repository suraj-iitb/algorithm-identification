//Counting Sort (keisuu)

#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000001
#define KMAX 10000

// NMAX youso count
// KMAX youso size

int main() {
	unsigned int *A,*B;
	int C[KMAX+1];
	int i,length;


	//init
	for(i=0;i<=KMAX;i++){
		C[i]=0;
	}


	//input
	scanf("%d",&length);

	A=malloc(sizeof(int) * length+1);
	B=malloc(sizeof(int) * length+1);

	//input
	for(i=1;i<=length;i++){
		scanf("%d",&A[i]);
	}


	for(i=1;i<=length;i++){
		C[A[i]]++;
	}

	for(i=1;i<=KMAX;i++){
		C[i]=C[i]+C[i-1];
	}

	for(i=length;i>=1;i--){
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}

	for(i=1;i<=length;i++){
		printf("%d",B[i]);
		if(i!=length){
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}

