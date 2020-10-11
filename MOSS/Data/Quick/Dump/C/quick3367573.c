#include <stdio.h>

#define INFTY 1000000000

typedef struct
{
  char mark;
  int number;
}Card;

void merge(Card B[],int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  Card L[n1],R[n2];
  for(i = 0;i < n1;i++)
    {
      L[i] = B[left + i];
    }
  for(i = 0;i < n2;i++)
    {
      R[i] = B[mid + i];
    }
  L[n1].number = INFTY;
  R[n2].number = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++)
    {
      if(L[i].number <= R[j].number)
	{
	  B[k] = L[i++];
	}
      else
	{
	  B[k] = R[j++];;
	}
    }
}
void mergeSort(Card B[],int left,int right)
{
  int mid;
  if(left + 1 < right)
    {
      mid = (left + right)/2;
      mergeSort(B,left,mid);
      mergeSort(B,mid,right);
      merge(B,left,mid,right);
    }
}
int partition(Card A[],int p,int n)
{
  int i,j;
  Card x,temp;
  x = A[n];
  i = p - 1;
  for(j = p;j < n;j++)
    {
      if(A[j].number <= x.number)
	{
	  i ++;
	  temp = A[i];
	  A[i] = A[j];
	  A[j] = temp;
	}  
    }
    temp = A[i + 1];
    A[i + 1] = A[n];
    A[n] = temp;
    
  return i+1;
}

void quicksort(Card A[],int p,int r)
{
  int q;
  if(p < r)
    {
      q = partition(A,p,r);
      quicksort(A,p,q - 1);
      quicksort(A,q + 1,r);
    }
}

int main()
{
  int n,i,f = 0;
  Card A[100000],B[100000];
  
  scanf("%d",&n);

  for(i = 0;i < n;i ++)
    {
      scanf("%s %d",&A[i].mark,&A[i].number);
      B[i].mark = A[i].mark;
      B[i].number = A[i].number;
    }

  quicksort(A,0,n - 1);
  mergeSort(B,0,n);

  for(i = 0;i < n;i++)
    {
      if(A[i].mark != B[i].mark)
	{
	  f = 1;
	}
    }

  if(f == 1)
    {
      printf("Not stable\n");
    }
  else
    {
      printf("Stable\n");
    }

  for(i = 0;i < n;i++)
    {
      printf("%c %d\n",A[i].mark,A[i].number);
    }
  return 0;
}

