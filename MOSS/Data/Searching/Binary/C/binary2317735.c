#include <stdio.h>


int search(int *a,int len,int key){
	int i=len/2+len%2;
	if(a[i]==key){
		return 1;
	}else if(a[i]<key){
		if(len==0){
			return 0;
		}else{
			return search(a+i,len-i,key);
		}
	}else if(a[i]>key){
		if(len==1){
			return 0;
		}else{
			return search(a,len-i,key);
		}
	}
	return 0;
}

int main(){
	int n,q;
	int S[100000];
	int T[50000];


	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);
	}
	int count=0;
	for(i=0;i<q;i++){
		count+=search(S,n,T[i]);
	}
	printf("%d\n",count);
	return 0;
}
