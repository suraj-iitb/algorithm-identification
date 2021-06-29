#include<stdio.h>

#define MAX 500000
#define SENTINEL 1000000001

int count;
int L[MAX/2+2],R[MAX/2+2];

void merge(int a[MAX],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++)L[i]=a[left+i];
	for(int i=0;i<n2;i++)R[i]=a[mid+i];
	L[n1]=SENTINEL;
	R[n2]=SENTINEL;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		count++;
		if(L[i]<=R[j]){
			a[k]=L[i++];
		}
		else a[k]=R[j++];
	}
}

void mergeSort(int a[MAX],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(a,n,left,mid);
		mergeSort(a,n,mid,right);
		merge(a,n,left,mid,right);
	}
}

int main(void){
	int a[MAX],n,i;
	count=0;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	mergeSort(a,n,0,n);
	
	for(int i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	
	printf("%d\n",count);
	
	return 0;
}
