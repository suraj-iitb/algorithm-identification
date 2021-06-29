#include <stdio.h>

#define N 100001
#define seNTInel 20000000

typedef struct Trump
{
	char mark;
	int value;
}Card;

Card L[N/2+2],R[N/2+2];

void Merge(Card A[],int n, int left, int mid,int right)
{
	int i,j,k,n1,n2;

	n1 = mid - left;
	n2 = right -mid;
	for(i = 0; i < n1; i++)
	{
		L[i] = A[left+i];
	}
	for(i = 0; i < n2; i++)
	{
		R[i] = A[mid+i];
	}

	L[n1].value = R[n2].value = seNTInel;
	i = j = 0;
	for(k = left; k <right; k++)
	{
		if(L[i].value <= R[j].value)
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
	}
}

void MergeSort(Card A[], int n, int left, int right)
{
	int mid;

	if(left +1 <right)
	{

		mid = (left+right)/2;
		MergeSort(A,n,left,mid);
		MergeSort(A,n,mid,right);
		Merge(A,n,left,mid,right);
	}
}

int partition(Card A[],int p,int r)
{
	int i,j;
	Card x,tmp;


	x = A[r];
	i = p-1;
	for(j = p; j < r; j++)
	{
		if(A[j].value <= x.value)
		{
			i = i+1;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
		tmp = A[i+1];
		A[i+1] = A[r];
		A[r] = tmp;
	
	return i+1;
}
				
void QuickSort(Card A[], int n,int p, int r)
{
	int q;

	if(p < r)
	{
		q = partition(A,p,r);
		QuickSort(A,n,p,q-1);
		QuickSort(A,n,q+1,r);
	}
}

int main()
{
	int n,i,v;

	Card A[N],B[N];
	char S[10];
	int stable =1;

	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%s %d",S,&v);
		A[i].mark = B[i].mark = S[0];
		A[i].value = B[i].value = v;
	}
	MergeSort(A,n,0,n);
	QuickSort(B,n,0,n-1);

	for(i = 0; i < n; i++)
	{
		if(A[i].mark != B[i].mark)
		{
		//	printf("安定でないところがあります%d\n",i);
			stable = 0;
		}
	}
		if(stable == 1)printf("Stable\n");
		else printf("Not stable\n");
		for(i = 0; i < n; i++)
		{
			printf("%c %d\n",B[i].mark,B[i].value);
		}

		return 0;
}


