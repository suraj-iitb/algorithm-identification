#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define SENTINEL 1000000001
void merge(int[],int,int,int);
void mergeSort(int[],int,int);
void printArray(int[],int);
int count=0;//the number of comparisons in the merge function
int main(void)
{
  int i;//counter
  int n;//the number of integers
  int arr[N];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&arr[i]);
  mergeSort(arr,0,n);
  printArray(arr,n);
  printf("%d\n",count);
  return 0;
}
void merge(int arr[],int left,int mid,int right)
{
  int i,j,k;//counter
  int n1=mid-left;//the number of elements in array l
  int n2=right-mid;//the number of elements in array r
  int *l=(int*)malloc(sizeof(int)*(n1+1));
  int *r=(int*)malloc(sizeof(int)*(n2+1));
  for(i=0;i<n1;i++) l[i]=arr[left+i];
  for(i=0;i<n2;i++) r[i]=arr[mid+i];
  l[n1]=SENTINEL;
  r[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(l[i]<=r[j])
	{
	  arr[k]=l[i];
	  i++;
	}
      else
	{
	  arr[k]=r[j];
	  j++;
	}
      count++;
    }
  free(l);
  free(r);
}
void mergeSort(int arr[],int left,int right)
{
  int mid;//separate point of array
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergeSort(arr,left,mid);
      mergeSort(arr,mid,right);
      merge(arr,left,mid,right);
    }
}
void printArray(int arr[],int n)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",arr[i]);
    }
  printf("\n");
}

