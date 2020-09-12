#include<iostream>
#include<cstdio>
using namespace std;

struct Card
{
	char mark;
	int value;
};

int merge(struct Card A[], int left, int mid, int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int i,j,k;
	struct Card L[50001];
	struct Card R[50001];
	
	for(i=0;i<=n1-1;i++) L[i]=A[left+i];
	for(i=0;i<=n2-1;i++) R[i]=A[mid+i];
	L[n1].value=2000000001;
	R[n2].value=2000000001;
	i=0;
	j=0;
	for(k=left;k<=right-1;k++)
	{
		if(L[i].value<=R[j].value)
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

int mergeSort(struct Card A[], int left, int right)
{
	int mid;
	if(left+1<right)
	{
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int partition(struct Card A[], int p, int r)
{
	int i,j;
	struct Card x,temp;
	
	x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j].value<=x.value)
		{
			i++;
			temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	}
	temp=A[r];
	A[r]=A[i+1];
	A[i+1]=temp;
	return i+1;
}

int quickSort(struct Card A[], int p, int r)
{
	int q;
	
	if(p<r)
	{
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	int i,n,v;
	struct Card A[100000],B[100000];
	char m[2];
	int s=0;
	
	scanf("%d",&n);
	
	for(i=0;i<=n-1;i++)
	{
		scanf("%s %d",m,&v);
		A[i].mark=B[i].mark=m[0];
		A[i].value=B[i].value=v;
	}
	
	quickSort(A,0,n-1);
	mergeSort(B,0,n);
	
	for(i=0;i<=n-1;i++)
	{
		if(A[i].mark!=B[i].mark) s=1;
	}
	
	if(s==0) printf("Stable\n");
	else printf("Not stable\n");
	
	for(i=0;i<=n-1;i++)
	{
		printf("%c %d\n",A[i].mark,A[i].value);
	}
	
	return 0;
}
