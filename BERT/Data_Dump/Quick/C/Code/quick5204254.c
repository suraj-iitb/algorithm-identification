#include <stdio.h>
#define N 100000
#define M 1000000000

typedef struct{
  char type;
  int num;
}Card;

Card L[N/2],R[N/2];

void merge(Card A[], int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0 ;i<n1;i++)
    {
      L[i] = A[left + i];
    }
  for (i = 0 ;i<n2;i++)
    {
      R[i] = A[mid + i];
    }
  L[n1].num = M;
  R[n2].num = M;
  i = 0;
  j = 0;
  for (k = left;k<right;k++)
    {
      if(L[i].num <= R[j].num)
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
}

void mergeSort(Card A[],int left,int right)
{
  int mid;
  if (left+1 < right)
    {
      mid = (left + right)/2;
      mergeSort(A,left,mid);
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}

int partition(Card A[],int p,int r)
{
  int i,j;
  Card key,x;
  x = A[r];
  i = p;
  for(j=p;j<r;j++)
    {
      if(A[j].num<=x.num)
        {
          key = A[i];
          A[i] = A[j];
          A[j] = key;
          i++;
        }
    }
  key = A[i];
  A[i] = A[r];
  A[r] = key;
  return i;
}

void quicksort(Card A[],int p,int r)
{
  int q,i;

  if (p < r){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int main(){
  int i,n,a=0;
  Card A[N],B[N];

  scanf("%d\n",&n);
  for(i=0;i<n;i++)
    {
      scanf("%c %d\n",&A[i].type,&A[i].num);
      B[i] = A[i];
    }
  mergeSort(B,0,n);
  quicksort(A,0,n-1);
  for(i=0;i<n;i++)
    {
      if(A[i].type != B[i].type)
        {
          a=1;
          break;
        }
    }
  if(a == 1)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].type,A[i].num);
  }
  return 0;
}

