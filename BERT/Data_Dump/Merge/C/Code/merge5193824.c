#include<stdio.h>
int count=0;
int main(void)
{
	int n;
	int S[500000];
	
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++) scanf("%d",&S[i]);
	mergeSort(S,0,n);
	for(int i=0;i<=n-1;i++)
	{
		if(i) printf(" ");
		printf("%d",S[i]);
	}
	printf("\n%d\n",count);
	return 0;
}


int merge(int A[], int left, int mid, int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int L[250001],R[250001];//を生成
	for(int i=0;i<=n1-1;i++) 
	L[i]=A[left+i];
	for(int i=0;i<=n2-1;i++) 
	R[i]=A[mid+i];
	L[n1]=1000000001;
	R[n2]=1000000001;
	int i=0;
	int j=0;
	for(int k=left;k<=right-1;k++)
	{
		count++;
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i = i + 1;
		}else{
			A[k]=R[j];
			j = j + 1;
		}
	}
}


int mergeSort(int A[], int left, int right)
{
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

