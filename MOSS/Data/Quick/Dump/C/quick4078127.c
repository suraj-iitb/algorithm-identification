
#include<stdio.h>

typedef struct
{
	char mark;
	int id,num;
} card;

int isstable(card *a,int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(a[i].num==a[i+1].num && a[i+1].id<=a[i].id)
		{
			return 0;
		}
	}

	return 1;
}
void swap(card *a,card *b)
{
		card tmp=*a;
		*a=*b;
		*b=tmp;
}
int partition(card *A,int p,int r)
{
	int x=A[r].num;
	int i=p-1;
	int j;
	for(j=p;j<=r-1;j++)
	{
		if(A[j].num<=x)
		{
			i=i+1;
			swap(&A[i],&A[j]);
		}
	}
	
	swap(&A[i+1],&A[r]);
	
	return i+1;
}	
void quicksort(card *A,int p,int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(void)
{
	int i,n;
	card A[500000];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c %d",&A[i].mark,&A[i].num);
		A[i].id=i;
	}
	quicksort(A,0,n-1);
	
	printf("%s\n",isstable(A,n)?"Stable":"Not stable");
	for(i=0;i<n;i++)
	{
		printf("%c %d\n",A[i].mark,A[i].num);
	}
	return 0;
}
