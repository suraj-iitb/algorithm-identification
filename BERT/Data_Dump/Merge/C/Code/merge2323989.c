#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int num = 0;
int main()
  {
    int n,s[500000],i;

    scanf("%d",&n);
    
    for(i = 0; i < n; i++){
      scanf("%d",&s[i]);
    }

    mergeSort(s,0,n);
    for(i = 0;i < n; i++){
      printf("%d",s[i]);
      if(i<n-1) printf(" ");
    }
    printf("\n%d\n",num);
    
    return 0;
  }

void merge(int *a,int left,int mid,int right)
{
  int n1,n2,i,j,k;
  // int *l,*r;

  n1 = mid - left;
  n2 = right - mid;
  // l = (int *)malloc(sizeof(int)*n1);
  // r = (int *)malloc(sizeof(int)*n2);
  int l[n1], r[n2];
  for(i = 0; i < n1; i++){
    l[i] = a[left+i];
  }
  for(i = 0;i < n2; i++){
    r[i] = a[mid+i];
  }
  l[n1] = INFTY;
  r[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    num++;
    if(l[i] <= r[j]){
      a[k] = l[i];
      i = i + 1;
    }
    else{
      a[k] = r[j];
      j = j + 1;
    }
  }
}

void mergeSort(int *a,int left,int right)
{
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}
