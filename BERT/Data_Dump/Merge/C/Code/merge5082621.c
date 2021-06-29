#include<stdio.h>

void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int k=0;

int main()
{
  int i,n,data[500000];

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&data[i]);
  }
  mergeSort(data,0,n);
  for( i=0 ; i<n ; i++ )
  {
    if(i==n-1)printf("%d\n",data[i]);
    else printf("%d ",data[i]);
  }
  printf("%d\n",k);
  return 0;  
}

void mergeSort(int *data,int left,int right)
{
  int mid,i;
  if( (left+1)<right )
  { 
    mid = (left+right)/2;
    mergeSort(data,left,mid);
    mergeSort(data,mid,right);
    merge(data,left,mid,right);
  }  
}

void merge(int *data,int left,int mid,int right)
{
  int i,j,a;
  int n1,n2;
  int l[250002],r[250002];
  n1=mid-left;
  n2=right-mid;
  for( i=0 ; i<n1 ; i++ )
    l[i]=data[left+i];
  for( i=0 ; i<n2 ; i++ )
    r[i]=data[mid+i];
  l[n1]=1215752670;
  r[n2]=1215752670;
  i=0;
  j=0;
  for( a=left ; a<right ; a++ )
  {
    k++;
    if( l[i]<=r[j])
    {
      data[a]=l[i];
      i++;
    }  
    else 
    {
      data[a]=r[j];
      j++;
    }    
  }
}  

