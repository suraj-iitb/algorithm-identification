
#include<stdio.h>
#define N 100

int main(void){
	int n,s;
	int A[N];
	int i,j,k;
	int p;
	
	scanf("%d",&n);
	
	for(i =0;i<n;i++){
		scanf("%d",&s);
		A[i] = s;
	}

	
	for(i=0;i<n;i++){
		p = A[i];
		j = i-1;
		while(j >= 0 && p < A[j]){
			A[j+1] = A[j];
			j--;
			A[j+1] = p;
		}
		for(j=0;j<n;j++){
			printf("%d",A[j]);
			if(j == n-1)printf("\n");
			else printf(" ");
		}
	}
	
	
	return 0;
}
