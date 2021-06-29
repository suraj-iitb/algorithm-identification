#include<stdio.h>

int linearsearch(int a[],int n,int key){
	int i=0;
	
	a[n] = key;
	while(a[i]!=key){
		i++;
	}
	if(i==n){
		return 0;
	}
	return 1;
}


int main(void){
	int n,q,i,x,count=0;
	
	scanf("%d",&n);
	
	int S[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	int T[n];
	
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	
	for(i=0;i<q;i++){
		x=linearsearch(S,n,T[i]);
		count+=x;
	}
	
	printf("%d\n",count);
	return 0;
}

