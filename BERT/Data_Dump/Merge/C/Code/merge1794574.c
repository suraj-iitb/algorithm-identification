#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000
 
void mergesort(int *,int,int);
void merge(int *,int,int,int);
 
int l[MAX/2+2],r[MAX/2+2];
int count;
int s[MAX];
 
int main()
{
 
  int n,i;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
 
  mergesort(s,0,n);
 
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",s[i]);
  }
  printf("\n");
  printf("%d\n",count);
 
  return 0;
}
 
 
 
void mergesort(int a[],int left,int right)
{
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(a,left, mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}
 
void merge(int a[],int left,int mid,int right)
{
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)
    l[i]=a[left+i];
  for(i=0;i<n2;i++)
    r[i]=a[mid+i];
  l[n1]=INFTY;
  r[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(l[i]<=r[j])
      a[k]=l[i++];
    else
      a[k]=r[j++];
  }
}
