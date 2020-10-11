#include<stdio.h>
#define N 100000
struct card
{
	char suit;
	int number;
};
struct card L[N/2+2];
struct card R[N/2+2];
struct card A[N];
struct card B[N]; 
int partition(struct card A[],int p,int r)
{
	int i=p-1;
	int j;
	struct card t;
	int x=A[r].number;
	for(j=p;j<r;j++)
	{
		if(A[j].number<=x)
		{
			i++;
			t=A[j];
			A[j]=A[i];
			A[i]=t;	
		}
	}
	t=A[r];
	A[r]=A[i+1];
	A[i+1]=t;
	return i+1;	
}
void quicksort(struct card A[],int p,int r)
{
	if(p<r)
	{
		int q;
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
void merge(struct card A[],int l,int m,int r)
{
	int i,j;
	for(i=0;i<m-l;i++)
	{
		L[i]=A[l+i];
	}
	for(i=0;i<r-m;i++)
	{
		R[i]=A[m+i];
	}
	i=j=0;
	int k=l;
	while(i!=m-l||j!=r-m)//没用标记法做 
	{
	//	cnt++;
		if(i==m-l)
		{
			A[k]=R[j];
			j++;k++;
		}
		else if(j==r-m)
		{
			A[k]=L[i];
			i++;k++;
		}
		else
		{
			if(L[i].number<=R[j].number)
			{
				A[k]=L[i];
				k++;i++;
			}
			else
			{
				A[k]=R[j];
				k++;j++;
			}
		}
	}
}
void mergesort(struct card A[],int l,int r)
{
	if(r-l>1)
	{
		int m;
		m=(l+r)/2;
		mergesort(A,l,m);
		mergesort(A,m,r);
		merge(A,l,m,r);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c %d",&A[i].suit,&A[i].number);
		getchar();
	}
	for(i=0;i<n;i++)
	{
		B[i]=A[i];
	}
	quicksort(A,0,n-1);
	mergesort(B,0,n);
	int s=0;
	for(i=0;i<n;i++)
	{
		if((B[i].suit)!=(A[i].suit))
		{
			s=1;
			break;
		}
	}
	if(s==0)
	{
		printf("Stable\n");
	}
	else
	printf("Not stable\n");
	for(i=0;i<n;i++)
	{
		printf("%c %d\n",(A[i].suit),A[i].number);
	}
	return 0; 
} 

