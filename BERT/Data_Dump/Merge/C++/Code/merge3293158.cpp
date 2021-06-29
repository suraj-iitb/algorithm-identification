#include<iostream>
#include<bits/stdc++.h>
#define max 500000
#define sentinel 2000000000
int count,L[max/2+2],R[max/2+2];
void merge(int *A,int l,int mid,int r);
void mergesort(int*A,int l,int r);
int main(void){
	int n,A[max];
	memset(A,0,sizeof(A));
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",A+i);
	count=0;
	mergesort(A,0,n);
	for(int i=0;i<n;i++){
		printf("%s%d",i==0? "":" ",A[i]);
	}
	printf("\n%d\n",count);
	return 0; 
}
void mergesort(int*A,int l,int r){
	if(l+1<r){
		int mid=(l+r)/2;
		mergesort(A,l,mid);
		mergesort(A,mid,r);
		merge(A,l,mid,r);
	}
	
}
void merge(int *A,int l,int mid,int r){
	int lenl,lenr,i,j,k;
	lenl=mid-l,lenr=r-mid;
	for(i=0;i<lenl;i++) L[i]=A[l+i];
	for(i=0;i<lenr;i++) R[i]=A[mid+i];
	L[lenl]=R[lenr]=sentinel;
	i=0,j=0;		
	for(k=l;k<r;k++){
		count++;
		if(L[i]<=R[j]) A[k]=L[i++];
		else A[k]=R[j++];
	}	
}
