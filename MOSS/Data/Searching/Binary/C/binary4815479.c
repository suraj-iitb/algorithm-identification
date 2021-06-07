#include <stdio.h>

#define L 100000

int main(void) {
	// your code goes here
	int i,n,q,left,right,mid,count=0;
	int S[L],T[L];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)scanf("%d",&T[i]);
	
	for(i=0;i<q;i++){
		left=0;
		right=n;
		while(left<right){
			mid=(left+right)/2;
			if(T[i]==S[mid]){
				count++;
				break;
			}else if(T[i]<S[mid]){
				right=mid;
			}else{
				left=mid+1;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

