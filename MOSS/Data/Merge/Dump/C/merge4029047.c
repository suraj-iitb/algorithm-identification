#include<stdio.h>

int cnt=0;
int l[500000];
int r[500000];
void merge(int A[],int n,int left,int mid, int right){
	int i;
	int n1=mid-left;
	int n2=right-mid;
	for(i=0; i<n1; i++){
		l[i]=A[left+i];
	}
	for(i=0; i<n2; i++){
		r[i]=A[mid+i];
	}
	
	l[n1]=r[n2]=1000000000;
	
	 i=0;
	int j=0;
	int k;
	
	for(k=left; k<right;k++){
		cnt++;
		if(l[i]<=r[j]){
			A[k]=l[i++];
		}else{
			A[k]=r[j++];
		}
	}
}

void mergeSort(int A[],int n,int left, int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,n,left,mid);
		mergeSort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}

int main(void){
	int A[500000],n,i;
	cnt=0;
	
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	mergeSort(a,n,0,n);
	
	for( i = 0; i < n-1; i++ ){
		printf( "%d ", a[i] );
	}
	printf( "%d\n", a[n-1] );
	
	printf( "%d\n", cnt );
	
	return 0;
}


	
