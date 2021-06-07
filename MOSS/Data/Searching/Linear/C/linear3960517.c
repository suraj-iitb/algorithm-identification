#include<stdio.h>
#define NOT_FOUND 0;

int linerSearch(int A[], int key, int n){
	int i=0;
	A[n] = key;
	while(A[i] != key){
		i++;
	}
	return i != n;
}

int main(void){
	int n,i,q;
	
	scanf("%d",&n);
	
	int S[n];
	
	for(i=0;i<n;i++){scanf("%d",&S[i]);}
	
	scanf("%d\n",&q);
	
	int T[q];
	
	for(i=0;i<q;i++){scanf("%d",&T[i]);}
	
	int k=0;
	for(i=0; i<q; i++){
		if(linerSearch(S,T[i],n)){
			k++;
		}
	}
	
	printf("%d\n",k);
	
	return 0;
}
