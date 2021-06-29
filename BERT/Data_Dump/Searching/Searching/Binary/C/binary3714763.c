#include<stdio.h>
int search(int *a,int n,int key){
	int left=0,right=n,mid;
	while(left<right){
		mid=(left+right)/2;
		if(a[mid]==key){
			return mid;
		}else if(a[mid]>key){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	return 0;
}
int main(){
	int n,a[100000+1],q,i,key,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(search(a,n,key)){
			sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
