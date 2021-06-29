#include <stdio.h>

#define N 10000
#define Q 500

int main(void){
	int S[N],T[Q],c=0,n,q,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&S[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++) scanf("%d",&T[i]);
	
	//search
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(T[i]==S[j]){
				c++;
				break;
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
