#include<stdio.h>
#define NOTFOUND -100

int n=0;
int binarySearch(int s[],int key){
	int left=0,right=n,mid=0;
	while(left < right){
		mid = (left + right)/2;
		if(s[mid] == key) return mid;
		else if(key < s[mid]) right = mid;
		else left = mid + 1;
	}
	return NOTFOUND;
}
int main(){
	int i,q,s[100000],t[50000],cnt=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&s[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++) scanf("%d",&t[i]);

	for(i=0;i<q;i++){
		if(binarySearch(s,t[i]) != NOTFOUND) cnt++;
	}
	printf("%d\n",cnt);

	return 0;
}
