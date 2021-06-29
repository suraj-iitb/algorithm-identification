#include<stdio.h>

int main(void){
	
	int n,S[100000],q,T[50000],i,j,C=0,mid,left,right;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &S[i]);	
	}
	
	scanf("%d",&q);
	for(j=0;j<q;j++){
		scanf("%d",&T[j]);
	}
	
	for(j=0;j<q;j++){
	left = 0;
	right = n;
	while(left<right){
		mid = (left+right)/2;
		if(S[mid] == T[j]){C++;break;}
		else if(S[mid]>T[j])right = mid;
		else left = mid+1;
	}
	}
	
	printf("%d\n",C);
	
	return 0;}
	
	
	
