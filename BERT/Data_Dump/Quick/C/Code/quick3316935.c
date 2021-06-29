#include <stdio.h>
#define N 100000
typedef struct{
  char mark;
  int num;
}card;
int partition(card *,int,int,int);
void quickSort(card *,int,int,int);
void mergeSort(card *,int,int,int);
void merge(card *,int,int,int,int);
card L[N/2+2],R[N/2+2];
int main()
{
  int i,v,n;
  card A1[N],A2[N];
  char S[10];
  int stable=1;
  /*入力*/
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%s %d",S,&v);
    A1[i].mark=A2[i].mark=S[0];
    A1[i].num=A2[i].num=v;
  }

  mergeSort(A1,n,0,n);
  quickSort(A2,n,0,n-1);


  for(i=0;i<n;i++)
  {
    if(A1[i].mark != A2[i].mark)
      stable = 0;
  }

  /*出力*/
  if(stable == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0;i<n;i++)
  {
    printf("%c %d\n",A2[i].mark,A2[i].num);
  }
return 0;
}

void quickSort(card A[],int n,int p,int r)
{
  int q;
  if(p < r)
    {
      q = partition(A,n,p,r);
      quickSort(A,n,p,q-1);
      quickSort(A,n,q+1,r);
    }
}

int partition(card A[],int n,int p,int r)
{
  int i,j;
  card x,y;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++)
  {
    if(A[j].num <= x.num)
    {
      i++;
      y=A[i];
      A[i]=A[j];
      A[j]=y;
    }
  }
  y=A[i+1];
  A[i+1]=A[r];
  A[r]=y;
  return i+1;
}
void merge(card A[],int n,int left,int mid,int right)
{
  int i,j,k,n1,n2,l;
  n1 = mid - left ;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i] = A[left + i];
  for(i=0;i<n2;i++)
    R[i] = A[mid + i];
  L[n1].num=R[n2].num=2000000000;
  i = 0;
  j = 0;
  for(k=left;k<right;k++)
    {
      if(L[i].num <= R[j].num)
        {
          A[k] = L[i++];
        }
      else
        {
          A[k] = R[j++];
        }
    }
}
void mergeSort(card B[],int n,int left,int right)
{
  int mid;
  if(left+1 < right)
  {
    mid = (left + right)/2;
     mergeSort(B,n,left,mid);
     mergeSort(B,n,mid,right);
    merge(B,n,left,mid,right);
  }
}

