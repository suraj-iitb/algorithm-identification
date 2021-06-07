#include<stdio.h>
#define MAX_n 10000
#define MAX_q 500
#define max 1000000000
int main(void){

	int n, q;
	int S[MAX_n], T[MAX_q];
	int i, j;
	int count=0;
	scanf("%d", &n);
	for(i =0;i<n;i++){
		scanf("%d", &S[i]);
	}
	
	scanf("%d", &q);
	for(i =0;i<q;i++){
		scanf("%d", &T[i]);
	}
	
	for(i =0;i<q;i++){
		for(j = 0;j<n;j++){
			if(T[i] == S[j]){
				count++;
				break;
			}
		}
	}
	
	
	printf("%d\n", count);



}
