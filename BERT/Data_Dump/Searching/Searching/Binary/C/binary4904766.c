#include<stdio.h>

#define N 100000

int binarysearch(int s[],int n,int t){
	
	int left,right,mid;
	
	left=0;
	right=n;
	while(left<right){
		mid=(left+right)/2;
		
		if(s[mid]==t){
			return 1;
		}
		else if(s[mid]<t){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return 0;
}

int main(void){
	
	int n,q,t,i;
	int s[N];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	int count=0;
	for(i=0;i<q;i++){
		scanf("%d",&t);
		if(binarysearch(s,n,t))count++;
	}
	
	printf("%d\n",count);
	
	return 0;
}

