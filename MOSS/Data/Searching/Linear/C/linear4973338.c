#include <stdio.h>


int main(void){
	int i,j,n,S[10000],q,T;
	int c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T);
	j=0;
	S[n]=T;
	while(S[j]!=T)j++;
	if(j!=n)c++;
	}
	printf("%d\n",c);
	
	return 0;

}
