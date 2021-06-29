#include<stdio.h>
int main(void){
	int i,j,n,q,left,right,mid,S[100000],T[50000],C=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	
	for(i=0;i<q;i++){
		left=0;
		right=n;
		while(left<right){
			mid=(left+right)/2;
			if(S[mid]==T[i]){
				C++;
				break;
			}else if(T[i]<S[mid]){
				right=mid;
			}else{
				left=mid+1;
			}
		}
	}
	
	printf("%d\n",C);
	return 0;
}
