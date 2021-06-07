#include <stdio.h>
int count=0;
void binarySearch(int S[],int T[],int n,int q);
int main(void){
	int i,n,q;
	scanf("%d",&n);
	int j = 0;
	int S[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	int T[q];
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	binarySearch(S,T,n,q);
	printf("%d\n",count);
	return 0;	
}
void binarySearch(int S[],int T[],int n,int q){
	int i,left,right,mid;
	for(i=0;i<q;i++){
	left=0;
	right=n;
		while(left<right){
			mid =(left+right)/2;
			if(S[mid]==T[i]){ 
			count++;
			break;
			}
			else if(T[i]<S[mid]){
				right=mid;
				}
				else {
				left=mid+1;
				}
			}
	}
}
