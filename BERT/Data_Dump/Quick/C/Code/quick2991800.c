#include<stdio.h>
#include<stdlib.h>
#define SENTINEL 1000000001
typedef struct
{
  char c;
  int x;
} card;
void quickSort(card*,int,int);
int partition(card*,int,int);
void swap(card*,int,int);
void merge(card*,int,int,int);//almost same function compared to 5B
void mergeSort(card*,int,int);//almost same function compared to 5B
int arrayCompare(card*,card*,int);
void printArray(card*,int);
int main(void)
{
  int i;//counter
  int n;//length of array
  int par;//partition number
  card *arr;
  card *stableArr;
  scanf("%d",&n);
  arr=(card*)malloc(sizeof(card)*n);
  stableArr=(card*)malloc(sizeof(card)*n);
  for(i=0;i<n;i++)
    {
      scanf(" %c %d",&arr[i].c,&arr[i].x);
      stableArr[i]=arr[i];
    }
  quickSort(arr,0,n-1);
  mergeSort(stableArr,0,n);
  if(arrayCompare(arr,stableArr,n)==1) printf("Stable\n");
  else printf("Not stable\n");
  printArray(arr,n);
  return 0;
}
void quickSort(card *arr,int p,int r)
{
  int q;
  if(p<r)
    {
      q=partition(arr,p,r);
      quickSort(arr,p,q-1);
      quickSort(arr,q+1,r);
    }
}
int partition(card *arr,int p,int r)
{
  int i;//counter
  int parlast;//last index of first half part
  int sep=arr[r].x;//separate number
  parlast=p-1;
  for(i=p;i<r;i++)
    {
      if(arr[i].x<=sep)
	{
	  parlast++;
	  swap(arr,parlast,i);
	}
    }
  swap(arr,parlast+1,r);
  return parlast+1;
}
void swap(card *arr,int x,int y)
{
  card temp;
  temp=arr[x];
  arr[x]=arr[y];
  arr[y]=temp;
}
void merge(card *arr,int left,int mid,int right)
{
  int i,j,k;//counter
  int n1=mid-left;//the number of elements in array l
  int n2=right-mid;//the number of elements in array r
  card *l=(card*)malloc(sizeof(card)*(n1+1));
  card *r=(card*)malloc(sizeof(card)*(n2+1));
  for(i=0;i<n1;i++) l[i]=arr[left+i];
  for(i=0;i<n2;i++) r[i]=arr[mid+i];
  l[n1].x=SENTINEL;
  r[n2].x=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(l[i].x<=r[j].x)
	{
	  arr[k]=l[i];
	  i++;
	}
      else
	{
	  arr[k]=r[j];
	  j++;
	}
    }
  free(l);
  free(r);
}
void mergeSort(card *arr,int left,int right)
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
int arrayCompare(card *arr1,card *arr2,int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(arr1[i].c!=arr2[i].c||arr1[i].x!=arr2[i].x) return 0;
    }
  return 1;
}
void printArray(card *arr,int n)
{
  int i;//counter
  for(i=0;i<n;i++) printf("%c %d\n",arr[i].c,arr[i].x);
}

