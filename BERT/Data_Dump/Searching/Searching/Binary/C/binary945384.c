#include<stdio.h>

#define MAX1 100000
#define MAX2 50000
void Search(int *,int);

int count=0;
 int right=0,left=0,mid=0;
int m;
int main()
{
  int n,i,j;
  int s[MAX1],t[MAX2];

  //ここからscan
  scanf("%d",&m);
  for(i=0;i<m;i++)
    {
      scanf("%d",&s[i]);
    }
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&t[i]);
    }
  //ここまで
  for(i=0;i<n;i++)
    {
      Search(s,t[i]);
    }
  printf("%d\n",count);
  return 0;
}

void Search(int *A,int key)
{
  left = 0;
  right = m;
  while(left<right)
    {
      mid = (left + right)/2;
      if(key==A[mid])
	{
	  count+=1;
	  break;
	}
      else if(key > A[mid])
	{
	  left = mid + 1;
	}
      else if(key < A[mid])
	{
	  right = mid;
	}
    }
}
