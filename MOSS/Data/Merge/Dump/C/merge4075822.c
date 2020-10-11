#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define INFTY 1000000001;

void mergeSort(int *,int,int);
void merge(int *,int ,int ,int);

int cnt;

int main()
{
  int n,i,S[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }

  mergeSort(S,0,n);



  for(i=0;i<n;i++)
  {
    if(i!=n-1)printf("%d ",S[i]);
    else printf("%d\n",S[i]);
  }
  printf("%d\n",cnt);

  return 0;
}


void merge(int S[] ,int left ,int mid ,int right)
{
  int n1,n2,k,*L,*R,i,j;
  n1 = mid - left;
  n2 = right - mid;
  // L[0...n1], R[0...n2] を生成
  L = (int *)malloc((n1+1)*sizeof(int));
  R = (int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n1;i++)L[i] = S[left + i];
  for(i=0;i<n2;i++)R[i] = S[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left;k<right;k++)
    {
      if( L[i] <= R[j])
        {
          S[k] = L[i];
          i = i + 1;
        }

      else
        {
          S[k] = R[j];
          j = j + 1;
        }
        cnt++;
    }
}

void mergeSort(int S[], int left, int right)//初期値：S,０、n
{
  int mid;
  if(left+1 < right)
    {
      mid = (left + right)/2;

      mergeSort(S, left, mid);

      mergeSort(S, mid, right);

      merge(S, left, mid, right);
    }
}

