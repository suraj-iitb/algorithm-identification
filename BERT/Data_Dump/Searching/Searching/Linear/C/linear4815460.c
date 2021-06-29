#include <stdio.h>

#define L 100000

int main(void) {
	// your code goes here
	int i,j,n,q,count=0;
	int S[L],T[L];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)scanf("%d",&T[i]);
	
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(S[j]==T[i]){
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
