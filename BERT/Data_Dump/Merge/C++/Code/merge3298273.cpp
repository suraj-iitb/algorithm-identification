#include<iostream>
#include<bits/stdc++.h>
#define MAX_N 500000 
#define limit 2000000000
using namespace std; 
int L[MAX_N/2+2],R[MAX_N/2+2],cnt;
void mergesort(int * A,int l,int r);
void merge(int *A,int l,int r,int mid);
int main(void){
	int A[MAX_N],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",A+i);
	cnt=0;
	mergesort(A,0,n);
	for(int i=0;i<n;i++) printf("%s%d",i==0? "":" ",A[i]);
	printf("\n%d\n",cnt);
}
void mergesort(int * A,int l,int r){
	if(l+1<r){
		int mid=(l+r)/2;
		mergesort(A,l,mid);
		mergesort(A,mid,r);
		merge(A,l,r,mid);
	}
}
void merge(int *A,int l,int r,int mid){
	int lenl,lenr,i,j,k;
	lenl=mid-l,lenr=r-mid;
	for(i=0;i<lenl;i++) L[i]=A[i+l];
	for(i=0;i<lenr;i++) R[i]=A[i+mid];
	L[lenl]=limit,R[lenr]=limit;
	i=0,j=0;
	for(k=l;k<r;k++){
		cnt++;
		if(L[j]<=R[i]){
			A[k]=L[j];
			j++;
		}
		else {
			A[k]=R[i];
			i++;
		}
	}
}
