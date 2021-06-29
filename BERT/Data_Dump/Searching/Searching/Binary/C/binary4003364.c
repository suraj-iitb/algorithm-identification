#include<stdio.h>
#include<stdlib.h>
#define MAX1 100000
#define MAX2 50000


int binary(int p[], int N1, int key){
	int left=0;
	int right=N1;
	
	for(;left<right;){
		int mid=(left+right)/2;
		if(p[mid]==key){
			return mid;
		}else if(key<p[mid]){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	
	return -1;
}

int main(void){
	
	int N1,N2,key;
	int p[MAX1];
	int cnt=0;
	
	scanf("%d",&N1);
	
	for(int i=0;i<N1;i++){
		scanf("%d",&p[i]);
	}
	
	scanf("%d",&N2);
	
	for(int i=0;i<N2;i++){
		scanf("%d",&key);
		
		int ans=binary(p,N1,key);
		if(ans!=-1){
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	
	return 0;
	
}
