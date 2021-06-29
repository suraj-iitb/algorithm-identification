#include<stdio.h>
#define N 500000

int cnt=0;

int a[N];

void merge(int left,int mid,int right){
	int L[N/2];
	int R[N/2];
	int i,j,idx;
	
	for(i=left;i<=mid;i++)
		L[i-left]=a[i];
	
	
	for(i=mid+1;i<=right;i++)
		R[i-mid-1]=a[i];

	i=0;  j=0;  idx=left;
	
	while(i<=(mid-left) && j<=(right-mid-1)){
		if(L[i] < R[j])
			a[idx++]=L[i++];
			
		else 
			a[idx++]=R[j++];
			
		cnt++;
	}
	
	while(i<=(mid-left)){
		a[idx++]=L[i++];
		cnt++;
	}
	
	while(j<=(right-mid-1)){
		a[idx++]=R[j++];
		cnt++;
	}
	
	return;
	
}

void mergeSort(int left,int right){
	int mid=(left+right)/2;
	
	if(left < right){
		mergeSort(left,mid);
		mergeSort(mid+1,right);
		merge(left,mid,right);
	}
	
	return;
	
}

int main(){
	int n,i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	mergeSort(0,n-1);
	
	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	
	printf("%d\n",cnt);
	
	return 0;
	
}
