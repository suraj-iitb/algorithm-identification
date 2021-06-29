/* ALDS1_4_A: Linear Search */
/* 20181115 AOJ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 10000
#define Q 500
int main(void){
	int n, S[N], q, T[Q], i = 0, j = 0, C = 0;

	scanf("%d", &n);
	while(i < n){
		scanf("%d", &S[i++]);
	}

	scanf("%d", &q);
	i = 0;
	while(i < q){
		scanf("%d", &T[i++]);
	}

	for(i = 0; i < q; i++ ){
		for(j = 0; j < n; j++){
			if(S[j] == T[i]){
				C++;
				break;
			}
		}
	}

	printf("%d\n", C);

	return 0;
}
