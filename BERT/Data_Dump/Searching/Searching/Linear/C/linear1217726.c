/*
 * Linear Search.c
 *
 *  Created on: 2015/02/15
 */
#include <stdio.h>

int S[10000]={0},T[1000]={0};
int flag[1000]={0};

void printarray(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}printf("\n");
}

int main(){
	int n,q;
	int i,j,counter=0;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}

	scanf("%d",&q);
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}

	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(S[j] == T[i]) flag[i]=1;
		}
	}

	for(i=0;i<q;i++){
		if(flag[i]==1)counter++;
	}
	printf("%d\n",counter);

	return 0;
}
