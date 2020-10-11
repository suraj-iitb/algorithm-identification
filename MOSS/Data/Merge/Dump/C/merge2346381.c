#include <stdio.h>

int merge(int, int, int);
int mergeSort(int, int);

int S[500000], L[250001], R[250001];
int count=0;

int main()
{
  int n, i;
  scanf("%d%",&n);
  for( i=0 ; i<n ; i++ )
    scanf("%d",&S[i]);

  mergeSort(0,i);

  for( i=0 ; i<n-1 ; i++ )
    printf("%d ",S[i]);
  printf("%d\n",S[i]);
  printf("%d\n",count);

  return 0;
}

int merge(int left, int mid, int right)
{
  int n1, n2, i, j, k;
  n1 = mid-left;
  n2 = right - mid;
  for( i=0 ; i<n1 ; i++ )
    L[i] = S[left+i];
  for( i=0 ; i<n2 ; i++ )
    R[i] = S[mid+i];
  L[n1]=1000000100;
  R[n2]=1000000100;
  i=0;
  j=0;
  for( k=left ; k<right ; k++ ){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }
    else{
      S[k]=R[j];
      j++;
    }
    count++;
  }
}
int mergeSort(int left, int right)
{
  int mid;
  if((left+1)<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}
