#include <stdio.h>

#define MAX 100000

int linearSearch(int S[],int T,int n)
{
	int i=0;
	S[n]=T;
	while(S[i]!=T){
		i++;
		if(i==n){return 0;}
	}
	return 1;
}

int main(void)
{
	int n,q,i,cnt=0;
	int S[MAX],T[MAX];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d", &q);
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	
	for(i=0;i<q;i++){
		cnt+=linearSearch(S,T[i],n);
	}
	printf("%d\n",cnt);
	
	return 0;
}
