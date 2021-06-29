#include<stdio.h>

int binarysearch(int a[],int n,int key){
	int left=0,right=n;
	int m;
	
	while(left<right){
		m = (left+right)/2;
		if(a[m]==key){
			return 1;
		}
		else if(key<a[m]){
			right = m;
		}
		else{
			left = m+1;
		}
	}
	return 0;
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
		x = binarysearch(S,n,T[i]);
		count+=x;
	}
	printf("%d\n",count);
	
	return 0;
}
