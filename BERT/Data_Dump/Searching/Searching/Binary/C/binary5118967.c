#include <stdio.h>

int main(void) 
{
	int n,m,i,j,a=0;
	scanf("%d",&n);
	int S[n];
	for(i=0; i<n; i++) {
		scanf("%d",&S[i]);
	}
	scanf("%d",&m);
	for(i=0; i<m; i++) {
		int x;
		scanf("%d",&x);
		int l=-1,r=n+1;
		while(l+1!=r) {
			int m=(l+r)/2;
			if(S[m]==x) {
				a++;
				break;
			}
			if(S[m]<x) {
				l=m;
			}
			else {
				r=m;
			}
		} 
	}
	printf("%d\n",a);
	return 0;
}
