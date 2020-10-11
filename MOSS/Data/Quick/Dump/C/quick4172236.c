#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char g;
	int num;
}card;
card B[100000];
card L[(100000 / 2) +1], R[(100000 / 2)+1];
int A[100000];
char C[100000][2];
int Partition(int A[], int p, int r)
{
	int x, i, j, tmp;
	char mark[2];
	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++)
  {
		if (A[j] <= x)
    {
			i++;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
			strcpy(mark,C[i]);
			strcpy(C[i],C[j]);
			strcpy(C[j],mark);
		}
	}
	tmp=A[i+1];
	A[i+1]=A[r];
	A[r]=tmp;
	strcpy(mark,C[i+1]);
	strcpy(C[i+1],C[r]);
	strcpy(C[r], mark);
	return i+1;
}
void Quick(int A[],int p,int r)
{
	int q;
	if(p<r)
  {
		q=Partition(A,p,r);
		Quick(A,p,q-1);
		Quick(A,q+1,r);
	}
}
void merge(int n,int left,int mid,int right) {
	int i, j, k;
	int n1=mid-left;
	int n2=right-mid;
	for(i=0;i<n1;i++)L[i]=B[left+i];
	for(i=0;i<n2;i++)R[i]=B[mid+i];
	L[n1].num=R[n2].num =200000;
	i=j=0;
	for(k=left;k<right;k++)
  {
		if(L[i].num<=R[j].num)B[k]=L[i++];
		else	B[k]=R[j++];
	}
}
void merge_sort(int n,int left,int right)
{
	int mid;
	if(left+1<right)
  {
		mid=(left+right)/2;
		merge_sort(n,left,mid);
		merge_sort(n,mid,right);
		merge(n,left,mid,right);
	}
}
int main()
{
	int i,n,q,flag = 1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
  {
		scanf("%s %d",C[i],&A[i]);
		B[i].g=*C[i];
		B[i].num=A[i];
	}
	Quick(A,0,n-1);
	merge_sort(n,0,n);
	for(i=0;i<n;i++)
  {
		if(*C[i]!=B[i].g||A[i]!= B[i].num)
    {
			flag=0;
			break;
		}
	}
	if(flag==0)printf("Not stable\n");
	else printf("Stable\n");

	for(i=0;i<n;i++)
  {
		printf("%s %d",C[i],A[i]);
		if(i!=n)printf("\n");
	}
	return 0;
}

