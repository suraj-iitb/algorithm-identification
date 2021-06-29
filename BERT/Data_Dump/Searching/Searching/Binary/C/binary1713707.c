#include<stdio.h>
int main(void){
	int n,S[100000],q,T[50000],C=0,i,left,right  ,key   ,mid;
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
		mid=(left+right)/2;
		key=T[i];
		while(left<=right){
			if(S[mid]==key){
				C++;
				break;
			}
			if(S[mid]<key){
				left=mid+1;
			}
			else if(S[mid]>key){
				right=mid-1;
			}
			mid=(left+right)/2;
		}
	}
	printf("%d\n",C);
	return 0;
}
