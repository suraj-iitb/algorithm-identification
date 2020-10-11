#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100010
#define inf 2000000000
struct card
{
	char suit;
	int value;
};
struct card l[MAX/2+10],r[MAX/2+10];
struct card A[MAX],a[MAX];
int q;
void merge(int left,int mid,int right)
{
	int i,Lstart=1,Rstart=1;
	int n1=mid-left;
	int n2=right-mid;
	for(i=1;i<=n1;i++)
		l[i]=A[left+i-1];
	for(i=1;i<=n2;i++)
		r[i]=A[mid+i-1];
	l[n1+1].value=inf;
	r[n2+1].value=inf;
	for(i=left;i<=right-1;i++)
	{
		
		if(l[Lstart].value<=r[Rstart].value)
		{
			A[i]=l[Lstart];
			Lstart++;
		}
		else
		{
			A[i]=r[Rstart];
			Rstart++;
		}
	}
	return;
}
void mergesort(int left,int right)
{
	if(left+1>=right)
		return;
	int mid=(left+right)/2;
	mergesort(left,mid);
	mergesort(mid,right);
	merge(left,mid,right);
	return;
}
void swap(int g,int y)
{
	struct card t;
	t.value=a[g].value;
	t.suit=a[g].suit;
	a[g].value=a[y].value;
	a[g].suit=a[y].suit;
	a[y].value=t.value;
	a[y].suit=t.suit;
	return;
}
void partition(int p,int r)
{
	int i,j,k;
	struct card x;
	i=p-1;
	j=p;
	x=a[r];
	for(k=p;k<=r-1;k++)
	{
		if(x.value<a[j].value)
			j++;
		else
		{
			i++;
			swap(i,j);
			j++;
		}
	}
	swap(i+1,r);
	q=i+1;
	return;
}
void quicksort(int left,int right)
{
	if(left>=right)
		return;
	partition(left,right);
	quicksort(left,q-1);
	quicksort(q+1,right);
	return;
}
int main()
{
	int n,i,flag=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c %d",&A[i].suit,&A[i].value);
		a[i]=A[i];
	}
	mergesort(1,n+1);
	quicksort(1,n);
	for(i=1;i<=n;i++)
		if(A[i].suit!=a[i].suit)
			flag=0;
	if(flag)
		printf("Stable\n");
	else
		printf("Not stable\n");
	for(i=1;i<=n;i++)
		printf("%c %d\n",a[i].suit,a[i].value);
	
	return 0;
}
