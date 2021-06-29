#include<stdio.h>
#define MAX 20000000

int L[MAX/2+1],R[MAX/2+1],count=0;

void mergeSort(int a[],int left,int right)
{
	void merge(int a[],int,int,int);
	if(left+1<right)
	{
		int mid=(left+right)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid,right);
		merge(a,left,mid,right);
	}
}

void merge(int a[],int left,int mid,int right)
{
	int i,j,cnt;
	int n1=mid-left;
	int n2=right-mid;
	for(i=0;i<n1;i++)
		L[i]=a[left+i];
	for(i=0;i<n2;i++)
		R[i]=a[mid+i];
	for(i=0,j=0,cnt=0;cnt<n1+n2;cnt++)
	{
		if(i>=n1)
		{
			a[left+cnt]=R[j];
			count++;
			j++;
		}
		else if(j>=n2)
		{
			a[left+cnt]=L[i];
			count++;
			i++;
		}
		else if(R[j]<=L[i])
		{
			a[left+cnt]=R[j];
			j++;
			count++;
		}
		else
		{
			a[left+cnt]=L[i];
			i++;
			count++;
		}
	}
}

int main()
{
	int n,s[500002];
	scanf("%d",&n);
	int i,ju=0;
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);
	mergeSort(s,0,n);
	for(i=0;i<n;i++)
	{
		if(ju++>0) printf(" ");
		printf("%d",s[i]);
	}
	printf("\n%d\n",count);
	return 0;
}
