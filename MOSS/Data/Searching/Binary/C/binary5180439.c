//このプログラムは未完成、同じ値があっても独立してカウントしてしまう
#include<stdio.h>
#define N 100000
#define Q 50000
int binarysearch(int,int);
int A[N];

int main()
{
  int i,j,x,y,B[Q],t_count[Q]={},cnt=0,eva;
  // printf("数列Aに値をいれてください。この数列は昇順になります\n");
  scanf("%d",&x); //A[i]について
  for(i=0;i<x;i++)
    {
      scanf("%d",&A[i]);
      eva = A[i];
      j = i-1;
      while(j>=0 && A[j] > eva)
	{
	  A[j+1]=A[j];
	  A[j]=eva;
	  j--;
	}
    }
  // printf("数列Bに値をいれてください。この数列は昇順になります\n");
  scanf("%d",&y); //B[i]について
  for(i=0;i<y;i++)
    {
      scanf("%d",&B[i]);
    }
  // algo
  for(i=0;i<y;i++)
    {
      if(binarysearch(B[i],x)==1 && t_count[i]!=1)
	{
	  t_count[i] = binarysearch(B[i],x);
     	}
    }
  for(i=0;i<y;i++)
    {
      if(t_count[i]==1)
	{
	  cnt++;
	}
    }
  printf("%d\n",cnt);
  return 0;
}

int binarysearch(int key,int n)
{
  int left=0,right=n,mid;
  while(left<right)
    {
      mid = (right+left)/2;
      if(A[mid] == key) return 1;
      else if(A[mid]>key) right = mid;
      else left = mid+1;
    }
  return 0;
}
     
  

