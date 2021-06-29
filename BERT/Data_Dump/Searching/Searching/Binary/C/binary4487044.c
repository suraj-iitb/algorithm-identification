#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bin_search(int S[],int left,int right,int x){
	int pivot=((right+left)/2);
	if(S[left]==x || S[right]==x || S[pivot]==x){
		return 1;
	}
	if(left > right){
		return 0;
	}
	int ans=0;

	if(S[pivot] > x){
		ans=bin_search(S,left+1,pivot,x);
	}else{
		ans=bin_search(S,pivot,right-1,x);
	}

	return ans;
}

int main(){
	int n,*S;
	int q,T;
	int count=0;

	scanf("%d",&n);
	S=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&T);
		count+=bin_search(S,0,n-1,T);
		
	}
	printf("%d\n",count);

   return 0;
}
