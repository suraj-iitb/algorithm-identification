#include<stdio.h>
#define M 10001
#define VM 2000001
int c[M],A[VM],B[VM];
int main(){
	int i,n,j,k;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++) c[A[i]]++;
	for(i=0,j=0;i<M;i++){
		while(c[i]){
			B[j]=i;
			j++;
			c[i]--;
		}
	}
	for(i=0;i<j;i++){
		if(i!=0) printf(" ");
		printf("%d",B[i]);
	}
	printf("\n");
} 
