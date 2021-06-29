#include <stdio.h>

#define INFTY 1000000000
#define N 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;

int main()
{
  int a,i,A[N];
  
  scanf("%d",&a);
  
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  
  mergeSort(A,0,a);
  
  for(i=0;i<a;i++){
    printf("%d",A[i]);
    if(i!=a-1) printf(" ");
  }
  
  printf("\n");
  
  printf("%d\n",count);

  return 0;
}


void merge(int A[],int left,int mid,int right)
{
  int i,j,k,s,t;
  int l[N/2+2],r[N/2+2];
  
  s = mid - left;
  t = right - mid;
  
  for(i=0;i<s;i++){
    l[i]=A[left+i];
  }
  
  for(i=0;i<t;i++){
    r[i]=A[mid+i];
  }
  
  l[s]=INFTY;
  r[t]=INFTY;
  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    count++;
    if(l[i]<=r[j]){
      A[k] = l[i];
      i=i+1;
    }
    else {
      A[k] = r[j];
      j=j+1;
    }
  }
}


void  mergeSort(int A[],int left,int right)
{
  int mid;
  
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

