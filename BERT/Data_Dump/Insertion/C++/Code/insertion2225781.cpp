#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	
	int a;
	scanf("%d", &a);
	int A[a];

	for (int i = 0; i < a; i++){
		scanf("%d", &A[i]);
	}

	for (int k = 0; k < a - 1; k++){
		printf("%d ", A[k]);
	}

	printf("%d\n", A[a - 1]);

	int key, j;

	for (int i = 1; i < a; i++){
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

		for (int k = 0; k < a - 1; k++){
			printf("%d ", A[k]);
		}

		printf("%d\n", A[a - 1]);
	}

	return 0;
}
