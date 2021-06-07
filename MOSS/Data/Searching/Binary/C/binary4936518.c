#include <stdio.h>

int A[1000000],n;

//二分探索 125ページ
int binary_search(int key){
	int left,mid,right;
	left=0; right=n;
	while(left<=right){
		mid=(left+right)/2;
		if(key==A[mid]){ return 1; }
		if(key>A[mid]){ left=mid+1; }
		else{ right=mid-1; }
	}
	return 0;
}

int main(void){
	int i,q,k,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){ scanf("%d",&A[i]); }
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&k);
		if(binary_search(k)){ sum++; }
	}
	printf("%d\n",sum);
	return 0;
}
