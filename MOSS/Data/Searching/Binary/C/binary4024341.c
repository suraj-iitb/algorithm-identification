#include <stdio.h>

int Search(int n,int s[],int k){
	int r,l,mid;
	r = n;
	l = 0;
	while(l < r){
		mid = (r + l)/2;
		if(s[mid] < k){
			l = mid + 1;
		}else if(s[mid] > k){
			r = mid;
		}else{
			return 1;
		}
	}
	return 0;
}

int main(void){
	int n,q,i,j,s[100000],key;
	int res = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(j=0;j<q;j++){
		scanf("%d",&key);
		if(Search(n,s,key))res++;
	}
	printf("%d\n",res);
	return 0;
}
