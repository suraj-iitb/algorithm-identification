#include<stdio.h>
#include<stdlib.h>
void countingSort(int[],int[],int,int);
void printArray(int[],int);
int main(void)
{
  int i;//counter
  int n;//length of array
  int max=0;//maximum value of array
  int *arr;
  int *sortedArr;
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  sortedArr=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
      if(max<arr[i]) max=arr[i];
    }
  countingSort(arr,sortedArr,n,max);
  printArray(sortedArr,n);
  return 0;
}
void countingSort(int arr[],int sortedArr[],int n,int max)
{
  int i;//counter
  int *countArr=(int*)malloc(sizeof(int)*(max+1));
  for(i=0;i<max+1;i++) countArr[i]=0;
  for(i=0;i<n;i++) countArr[arr[i]]++;
  for(i=1;i<max+1;i++) countArr[i]+=countArr[i-1];
  for(i=n-1;i>=0;i--)
    {
      sortedArr[countArr[arr[i]]-1]=arr[i];
      countArr[arr[i]]--;
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

