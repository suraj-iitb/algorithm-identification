#include<stdio.h>
	int linearSearch(int);
	int n,q;
    int A[10000],T[10000];

int main(){
	int i,count=0;

	scanf("%d",&n);

	for(i=0 ; i<n ; i++){
		scanf("%d",&A[i]);
	}

	scanf("%d",&q);

	for(i=0 ; i<q ; i++){
		scanf("%d",&T[i]);
	}

	for(i=0 ; i<q ; i++){
		count += linearSearch(T[i]);
	}

	printf("%d\n",count);

	return 0;
}

int linearSearch(int x){
	int i;
	for(i=0 ; i<n ; i++){
		if(A[i]==x)return 1;
	}

	return 0;
}
