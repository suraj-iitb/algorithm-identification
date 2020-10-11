#include<stdio.h>
#include<stdlib.h>

#define INFINITY 2000000000

int cnt=0;

void merge(int* a,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++){
		L[i]=a[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=a[mid+i];
	}
	L[n1]=INFINITY;
	R[n2]=INFINITY;
	int i=0;
	int j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i]<=R[j]){
			a[k]=L[i];
			i=i+1;
		}else{
			a[k]=R[j];
			j=j+1;
		}
	}
}

void msort(int* a,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		msort(a,left,mid);
		msort(a,mid,right);
		merge(a,left,mid,right);
	}
}

int main(void){

	int n;
	scanf("%d",&n);
	int* s=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	msort(s,0,n);
	
	
	for(int i=0;i<n;i++){
		printf("%d",s[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n%d\n",cnt);
	return 0;

}
