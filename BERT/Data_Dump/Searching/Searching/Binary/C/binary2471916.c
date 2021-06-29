#include <stdio.h>

int left=0,right=0,n;
int A[100005];

int Binary(int key){
	left=0;
	right=n;
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(key==A[mid]) return 1;
	    if(key<A[mid]){
			right=mid;
		}else {
			left=mid+1;
		}
	}
	return 0;
}


int main(){
	int sum=0,i=0,q,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&k);
		if(Binary(k))
		sum++;
	}
	
	printf("%d\n",sum);
	return 0;
}
