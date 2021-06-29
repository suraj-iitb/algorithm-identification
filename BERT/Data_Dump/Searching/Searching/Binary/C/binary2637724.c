#include <stdio.h>

int s[1000000],n;
int binarySearch(int key){
	int left=0;
	int right=n;
	int mid;
	while(left<right){
		mid=(left+right)/2;

		if(key>s[mid]){
			left=mid+1;
		}else if(key<s[mid]){
			right=mid; 
		}else{
			return 1;
		}
	}
	

	return 0;
}

int main(void){
	int i,q,count=0;
	int t[1000000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&t[i]);
	}
	for(i=0;i<q;i++){
		if(binarySearch(t[i])){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
