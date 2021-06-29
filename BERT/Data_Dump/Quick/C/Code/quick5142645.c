#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
  char pat;
  int val;
}Card;

void merge(Card [],int ,int ,int);
void mergeSort(Card [],int ,int);
int partition(Card [],int ,int);
void quickSort(Card [],int ,int);

int main()
{
  char pa[2];
  int n,v;
  Card *A,*B;
  int stable = 1;
  int i;
  
  scanf("%d",&n);
  if(!(n>=1 && n<=100000)) exit(1);
  
  A = (Card *)malloc(sizeof(Card)*(n+1));
  B = (Card *)malloc(sizeof(Card)*(n+1));

  for(i=0;i<n;i++)
    {
      scanf("%s %d",pa,&v);    
      A[i].pat = pa[0];
      B[i].pat = pa[0];
      A[i].val = v;
      B[i].val = v;
    }
  
  mergeSort(A,0,n);
  quickSort(B,0,n-1);

  for(i=0;i<n;i++)
    {
      if(A[i].pat != B[i].pat) stable = 0;
    }

  if(stable == 1) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++)
    {
      printf("%c %d\n",B[i].pat,B[i].val);
    }
  return 0;
}

void merge(Card A[],int left,int mid,int right)
{
  int n1,n2;
  int i,j,k;
  Card *L,*R;
  
  n1 = mid - left;
  n2 = right - mid;

  L = (Card *)malloc(sizeof(Card) * (n1 + 2));
  R = (Card *)malloc(sizeof(Card) * (n2 + 2));
  
  for(i = 0;i<n1;i++)
    {
      L[i] = A[left + i];
    }
  for( i = 0;i<n2;i++)
    {
      R[i] = A[mid + i];
    }
  L[n1].val = ((int)INFINITY);
  R[n2].val = ((int)INFINITY);
  i = 0;
  j = 0;
  for(k=left;k<right;k++)
    {
       if(L[i].val <= R[j].val)
        {
          A[k] = L[i];
          i++;
        }
      else
        {
          A[k] = R[j];
          j++;
        }
    }
  free(L);
  free(R);
}

void mergeSort(Card A[],int left,int right)
{
  int mid;
  if(left+1<right)
    {
      mid = (left+right)/2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}

int partition(Card A[],int p,int r)
{
  int i,j;
  Card tmp,x;
  
  x = A[r];
  i = p-1;

  for(j=p;j<r;j++)
    {
      if(A[j].val<=x.val)
        {
          i++;
          tmp = A[j];
          A[j] = A[i];
          A[i] = tmp;
        }
    }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

void quickSort(Card A[],int p,int r)
{
  int q;
  if(p < r)
    {
      q = partition(A,p,r);
      quickSort(A,p,q-1);
      quickSort(A,q+1,r);
    }
}


