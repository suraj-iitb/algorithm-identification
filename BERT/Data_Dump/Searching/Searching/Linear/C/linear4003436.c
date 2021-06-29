#include<stdio.h>
#include<stdlib.h>

#define N_MAX 10000
#define Q_MAX 500

int linearsearch(int n,int* A,int key){
	
	int i=0;
	A[n]= key;
	while (A[i]!=key){
		i++;
	}
	if(i>=n){
		return N_MAX+1;
	}
	return i;
	
}

int main(void){

	int A[N_MAX+1];
	int n;
	int B[Q_MAX+1];
	int q;
	int s=0;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&B[i]);
	}
	
	for(int i=0;i<q;i++){
		if(linearsearch(n,A,B[i])!=N_MAX+1)s++;
	}
	
	printf("%d\n",s);
	
	return 0;
}
