#include<stdio.h>

int linearSearch(int,int [10000],int);

int main(void){
	int n,q,count=0,i,j;
	int S[10000],T[10000];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	
	for(i=0;i<q;i++){
		if(linearSearch(T[i],S,n)!=0){
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

int linearSearch(int T,int S[10000],int n){
	int i;
	
	for(i=0;i<n;i++){
		if(T==S[i]){
			return 1;
		}
	}
	
	return 0;
}

