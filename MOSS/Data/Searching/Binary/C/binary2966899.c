#include<stdio.h>
#define N 100000

int binary_search(int a[],int key,int n){
	int left=0;
	int right=n-1;
	
	while(left <= right){
		int mid=(left+right)/2;
		
		if(a[mid]==key)return 1;
		
		else if(a[mid] < key){
			left=mid+1;
		}
		
		else {
			right=mid-1;
		}
	}
	
	return 0;
}

int main(){
	int n,i,q,x;
	int a[N];
	int cnt=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++){
		scanf("%d",&x);
		cnt+=binary_search(a,x,n);
	}
	
	printf("%d\n",cnt);
	
	return 0;
	
}
