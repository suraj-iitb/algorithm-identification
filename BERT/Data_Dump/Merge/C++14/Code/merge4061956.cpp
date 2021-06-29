#include<stdio.h>
#define MAX 500000
#define INF (1<<30)

int L[MAX], R[MAX],cnt;

void merge(int* A, int l, int mid, int r){
	int n1,n2,i,j,k;
	n1=mid-l;	n2=r-mid;
	for(i=0;i<n1;i++){
		L[i]=A[l+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=R[n2]=INF;

	i=j=0;
	for(k=l;k<r;k++){
			cnt++;
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}

void MergeSort(int* A, int l, int r){
	int mid;
	if(r-l>1){
		mid=(l+r)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid,r);
		merge(A,l,mid,r);
	}
}

int main(){
	int i,n,A[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);

	cnt=0;
	MergeSort(A,0,n);

	for(i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",A[i]);
	}printf("\n%d\n",cnt);
	return 0;
}

