#include <stdio.h>
int binarySearch(int);
int n,s[100000];
int main(){
	int q,t[50000],i,cnt=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&s[i]);

	scanf("%d",&q);
	for(i=0;i<q;i++) scanf("%d",&t[i]);
	
	for(i=0;i<q;i++){
		if(binarySearch(t[i])==1) cnt++;
	}
	
	printf("%d\n",cnt);
	
	return 0;
}

int binarySearch(int key){
	int left=0,right=n,mid;
	
	while(left<right){
		mid=(left+right)/2;
		if(s[mid]==key) return 1;
		else if(key<s[mid]) right=mid;
		else left=mid+1;
	}
	return 0;
}
	
