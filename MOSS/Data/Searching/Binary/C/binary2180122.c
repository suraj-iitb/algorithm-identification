#include<stdio.h>

int main(){
	int min(int x, int y){
		if(x<y) return x;
		else return y;
	}
	int max(int x, int y){
		if(x>y) return x;
		else return y;
	}
	int i, j;
	int n,q;
	scanf("%d",&n);
	int S[n];
	for(i=0;i<n;i++)
	scanf("%d",&S[i]);
	scanf("%d",&q);
	int T[q];
	for(i=0;i<q;i++)
	scanf("%d",&T[i]);
	int left,right,mid;
	int count=0;
	left=0;
	right=n-1;
	mid=(n-1)/2; 

	for(i=0;i<q;i++){
		if(T[i]<=S[n-1] && T[i]>=S[0]){
		while(left<right){
			if(S[mid]==T[i]){
				count++;
				left=right;}
			else if(S[mid]<T[i]){
				left=max(left+1,mid);
				if(left > mid){if(S[left]==T[i]) count++;}
				mid=(left+right)/2;
				}
			else if(S[mid]>T[i]){
				right=min(right-1,mid);
				if(right < mid){if(S[right]==T[i]) count++;}
				mid=(left+right)/2;
				}
		}
		left=0;
		right=n-1;
		mid=(n-1)/2;
		}
	}
	printf("%d\n",count); 
	return 0;
}
