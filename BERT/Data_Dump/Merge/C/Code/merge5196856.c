#include<stdio.h>
int L[250000],R[250000],p=0,s[500000];
void merge(int a[],int l,int mid,int r)
{
	int n1,n2,i,j,k;
	n1=mid-l+1;
	n2=r-mid;
	for(i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=a[mid+i+1];
	}
	for(i=0,j=0,k=l;k<r&&i<n1&&j<n2;k++)
	{p++;
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
	for (i;i<n1;i++)
	{p++;
		a[k++]=L[i];
	} 
	for (j;j<n2;j++)
	{p++; 
		a[k++]=R[j]; 
	} 
}
void mergesore(int a[],int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		mergesore(a,l,mid);
		mergesore(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	mergesore(s,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",s[i]);
		if(i==n-1)
		printf("\n");
		else
		printf(" ");
	}
	printf("%d\n",p);
}
