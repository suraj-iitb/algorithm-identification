#include <stdio.h>

int L[500000/2+2],R[500000/2+2],count=0,n;

void merge(int A[],int left,int mid,int right){
	int n1,n2,i,j,k,s,t;
	n1=mid-left;
	n2=right-mid;
	for(i=0;i<n1;i++)
		L[i]=A[left+i];
	for(i=0;i<n2;i++)
		R[i]=A[mid+i];
	L[n1]=2000000000;
	R[n2]=2000000000;
	i=j=0;
	for(k=left;k<right;k++){
		count++;
		if(L[i]<=R[j]){
			s=A[k];
			A[k]=L[i];
			L[i]=s;
			i=i+1;
		}
		else{
			t=A[k];
			A[k]=R[j];
			R[j]=t;
			j=j+1;
		}
	}
}

void mergeSort(int A[],int left,int right){
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(){
	int i,A[500000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	mergeSort(A,0,n);
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i<n-1)
			printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}
