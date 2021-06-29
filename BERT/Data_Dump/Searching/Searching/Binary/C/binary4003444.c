#include <stdio.h>

#define MAX 100000

int binarySearch(int S[], int T, int n)
{
	int left=0, right=n, mid;
	while(left<right){
		mid=(left+right)/2;
		if(S[mid]==T) {return 1;}
		else if(T<S[mid]){right=mid;}
		else {left=mid+1;}
	}
	return 0;
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
		cnt+=binarySearch(S,T[i], n);
	}
	printf("%d\n",cnt);
	
	return 0;
}
